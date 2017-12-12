/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:41:44 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/12 15:46:41 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_bool		check_errors(char *args)
{
	int				i;

	i = 0;
	while (args && args[i])
	{
		if (!ft_isdigit(args[i]) && (args[i] != '-' && args[i] != ' '
			&& args[i] != '+'))
		{
			ft_printf("bouh1");
			return (B_FALSE);
		}
		if ((args[i] == '-' || args[i] == '+')
			&& ((i > 0 && args[i - 1] != ' ') || !ft_isdigit(args[i + 1])))
		{
			ft_printf("bouh2");
			return (B_FALSE);
		}
		i++;
	}
	return (B_TRUE);
}

static t_bool		create_stack(size_t *nb_elem, t_stack **a, char **args)
{
	t_elem			*node;
	t_elem			*cur;
	int				nb;

	node = NULL;
	*a = ps_create_list();
	while (args && args[*nb_elem])
	{
		if (!ft_batoi(&nb, args[*nb_elem]))
			return (B_FALSE);
		node = ps_create_elem(nb);
		ps_add_end(a, node);
		cur = (*a)->start;
		while (cur != (*a)->end)
		{
			if (node->nb == cur->nb)
				return (B_FALSE);
			cur = cur->next;
		}
		(*nb_elem)++;
	}
	return (B_TRUE);
}

t_bool				parsing_args(size_t *nb_elem, t_stack **a, char **args)
{
	char			*str;
	char			*tmp;
	t_bool			error;
	char			**tab;

	tmp = ft_tabtostr(args);
	str = ft_strtrimall(tmp);
	ft_strdel(&tmp);
	if (!check_errors(str))
		return (B_FALSE);
	tab = ft_strsplit(str, ' ');
	ft_strdel(&str);
	error = create_stack(nb_elem, a, tab);
	free_tab(&tab);
	return (error);
}
