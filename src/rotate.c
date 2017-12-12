/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 00:11:06 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/12 14:29:27 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void				rotate_a(t_stack **a, t_stack **b, t_bool sort)
{
	if (sort)
		ft_printf("ra\n");
	if (a && *a && (*a)->nb_elems > 1)
	{
		(*a)->start = (*a)->start->next;
		(*a)->end = (*a)->end->next;
	}
	b = (t_stack **)b;
}

void				rotate_b(t_stack **a, t_stack **b, t_bool sort)
{
	if (sort)
		ft_printf("rb\n");
	if (b && *b && (*b)->nb_elems > 1)
	{
		(*b)->start = (*b)->start->next;
		(*b)->end = (*b)->end->next;
	}
	a = (t_stack **)a;
}

void				rotate_ab(t_stack **a, t_stack **b, t_bool sort)
{
	if (sort)
		ft_printf("rr\n");
	rotate_a(a, b, B_FALSE);
	rotate_b(a, b, B_FALSE);
}
