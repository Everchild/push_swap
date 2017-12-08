/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:37:50 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/08 00:25:18 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_bool		is_sorted(t_stack *a)
{
	t_elem			*cur;

	cur = a->start;
	while (cur != a->end)
	{
		if (cur->nb > cur->next->nb)
			return (B_FALSE);
		cur = cur->next;
	}
	return (B_TRUE);
}

//static void			small_list(void)
//{
//	ft_printf("small list\n");
//}

/*static size_t		prep_subdivision(t_stacks *stacks, size_t n, size_t nb_elem, size_t rest)
{
	int				n_to_push;

	n = nb_elem / 4;
	while (n > (20 * nb_elem / 100))
	{
//		while (stacks->a->nb_elems > n)
//		{
//			n_to_push = find_n_edge()
//		}
		n /= 4
	}
	return (n);
}*/

static void			big_list(size_t n, size_t nb_elem, t_stacks *stacks)
{
	size_t			rest;
	int				n_to_push;

	if (!n)
		n = 20 * nb_elem / 100;
	while (stacks->a->nb_elems > n)
	{
		n_to_push = find_n_edge(&(stacks->a), n, B_TRUE);
//		while (1){} // 4 leaks / 10
//		if (nb_elem > 200)
//			push_n_smallest_b(stacks, n, n_to_push, B_FALSE);
//		else
			push_n_smallest_b(stacks, n, n_to_push, B_TRUE);
	}
	rest = stacks->a->nb_elems;
	n_to_push = find_n_edge(&(stacks->a), n, B_TRUE);
//	while (1) {} // 10 leaks / 10
	push_n_smallest_b(stacks, rest, n_to_push, B_FALSE);
	sort_insert(&(stacks->a), &(stacks->b), rest, n);
}

void				choose_algo(t_stacks *stacks, size_t nb_elem)
{
	size_t			n;
	size_t			rest;

	n = 0;
	rest = 0;
	if (!is_sorted(stacks->a))
	{
//		if (nb_elem <= 6)
//			small_list();
//		else
//		{
//			if (nb_elem > 200)
//				n = prep_subdivision(stacks, n, nb_elem, rest);
			big_list(n, nb_elem, stacks);
//		}
	}
}
