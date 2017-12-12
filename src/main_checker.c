/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:47:03 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/12 15:22:59 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_instr		*get_instructions(void)
{
	static t_instr	ret[NB_INSTR] = {
	{ "sa", &swap_a },
	{ "sb", &swap_b },
	{ "ss", &swap_ab },
	{ "pa", &push_a },
	{ "pb", &push_b },
	{ "ra", &rotate_a },
	{ "rb", &rotate_b },
	{ "rr", &rotate_ab },
	{ "rra", &reverse_rotate_a },
	{ "rrb", &reverse_rotate_b },
	{ "rrr", &reverse_rotate_ab }
	};

	return (ret);
}

static int			check_sort(t_stack **a, t_stack **b)
{
	t_elem			*cur;

	if ((*b)->start)
		return (PS_KO);
	cur = (*a)->start;
	while (cur != (*a)->end)
	{
		if (cur->nb >= cur->next->nb)
		{
			ps_free_list(a);
			ps_free_list(b);
			return (PS_KO);
		}
		cur = cur->next;
	}
	ps_free_list(a);
	ps_free_list(b);
	return (PS_OK);
}

static int			exec_instr(t_stack **a, t_stack **b, char *inst)
{
	t_instr			*all_inst;
	int				i;

	i = 0;
	all_inst = get_instructions();
	while (i < NB_INSTR)
	{
		if (!ft_strcmp(inst, all_inst[i].str))
			break ;
		i++;
	}
	if (i == NB_INSTR)
		return (PS_ERROR);
	all_inst[i].instr(a, b, B_FALSE);
	return (PS_OK);
}

static int			ps_check(t_stack **a)
{
	t_stack			*b;
	char			*inst;
	int				gnl_ret;

	b = ps_create_list();
	inst = NULL;
	if (*a && b)
	{
		while ((gnl_ret = get_next_line(0, &inst)) > 0)
		{
			if (exec_instr(a, &b, inst) == PS_ERROR)
				return (PS_ERROR);
			ft_strdel(&inst);
		}
		if (!gnl_ret)
			return (check_sort(a, &b));
	}
	return (PS_ERROR);
}

int					main(int argc, char **argv)
{
	size_t			nb_elem;
	t_stack			*stack;
	int				result;

	nb_elem = 0;
	stack = NULL;
	if (argc <= 1)
		ft_printf("usage: ./checker <nb1> <nb2> <...>\n");
	else
	{
		if (!parsing_args(&nb_elem, &stack, argv + 1))
			ft_printf("Error\n");
		else
		{
			result = ps_check(&stack);
			if (result == PS_OK)
				ft_printf("OK\n");
			else if (result == PS_KO)
				ft_printf("KO\n");
			else if (result == PS_ERROR)
				ft_printf("Error\n");
		}
	}
	return (0);
}
