/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:24:09 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/12 14:29:25 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void				reverse_rotate_a(t_stack **a, t_stack **b, t_bool sort)
{
	if (sort)
		ft_printf("rra\n");
	if (a && *a && (*a)->nb_elems > 1)
	{
		(*a)->start = (*a)->start->prev;
		(*a)->end = (*a)->end->prev;
	}
	b = (t_stack **)b;
}

void				reverse_rotate_b(t_stack **a, t_stack **b, t_bool sort)
{
	if (sort)
		ft_printf("rrb\n");
	if (b && *b && (*b)->nb_elems > 1)
	{
		(*b)->start = (*b)->start->prev;
		(*b)->end = (*b)->end->prev;
	}
	a = (t_stack **)a;
}

void				reverse_rotate_ab(t_stack **a, t_stack **b, t_bool sort)
{
	if (sort)
		ft_printf("rrr\n");
	reverse_rotate_a(a, b, B_FALSE);
	reverse_rotate_b(a, b, B_FALSE);
}
