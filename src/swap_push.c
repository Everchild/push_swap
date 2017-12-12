/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:26:51 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/12 14:28:53 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void				swap_a(t_stack **a, t_stack **b, t_bool sort)
{
	if (sort)
		ft_printf("sa\n");
	if (a && *a && (*a)->nb_elems > 1)
		ps_swap_nodes(&(*a)->start, &(*a)->start->next);
	b = (t_stack **)b;
}

void				swap_b(t_stack **a, t_stack **b, t_bool sort)
{
	if (sort)
		ft_printf("sb\n");
	if (b && *b && (*b)->nb_elems > 1)
		ps_swap_nodes(&(*b)->start, &(*b)->start->next);
	a = (t_stack **)a;
}

void				swap_ab(t_stack **a, t_stack **b, t_bool sort)
{
	if (sort)
		ft_printf("ss\n");
	swap_a(a, b, B_FALSE);
	swap_b(a, b, B_FALSE);
}

void				push_a(t_stack **a, t_stack **b, t_bool sort)
{
	t_elem			*new;

	if (sort)
		ft_printf("pa\n");
	if (b && *b && (*b)->nb_elems >= 1)
	{
		new = ps_create_elem((*b)->start->nb);
		ps_add_start(a, new);
		ps_remove_node(b, &(*b)->start);
	}
}

void				push_b(t_stack **a, t_stack **b, t_bool sort)
{
	t_elem			*new;

	if (sort)
		ft_printf("pb\n");
	if (a && *a && (*a)->nb_elems >= 1)
	{
		new = ps_create_elem((*a)->start->nb);
		ps_add_start(b, new);
		ps_remove_node(a, &(*a)->start);
	}
}
