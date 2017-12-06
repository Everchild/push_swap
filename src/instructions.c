/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 00:11:06 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/06 18:23:59 by sbrochar         ###   ########.fr       */
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
		new = ps_create_elem((*b)->start->nb);
		ps_add_start(b, new);
		ps_remove_node(a, &(*a)->start);
	}
}

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
