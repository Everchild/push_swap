/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_small_lists.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:40:51 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/08 04:51:52 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void			sort_three_elem_b(t_stack **a, t_stack **b)
{
	t_elem			*smallest;

	smallest = (*b)->start;
	if (smallest->nb > smallest->next->nb)
		smallest = smallest->next;
	if (smallest->nb > (*b)->end->nb)
		smallest = (*b)->end;
	if (smallest == (*b)->start)
		rotate_b(a, b, B_TRUE);
	else if (smallest != (*b)->end)
		reverse_rotate_b(a, b, B_TRUE);
	if ((*b)->start->nb < (*b)->start->next->nb)
		swap_b(a, b, B_TRUE);
}

static void			sort_three_elem(t_stack **a, t_stack **b, t_bool isa)
{
	t_elem			*biggest;

	if (isa)
	{
		biggest = (*a)->start;
		if (biggest->nb < biggest->next->nb)
			biggest = biggest->next;
		if (biggest->nb < (*a)->end->nb)
			biggest = (*a)->end;
		if (biggest == (*a)->start)
			rotate_a(a, b, B_TRUE);
		else if (biggest != (*a)->end)
			reverse_rotate_a(a, b, B_TRUE);
		if ((*a)->start->nb > (*a)->start->next->nb)
			swap_a(a, b, B_TRUE);
	}
	else
		sort_three_elem_b(a, b);
}

static void			moar_small_lists(t_stacks *stacks, size_t nb_elem)
{
	int				n_to_push;

	if (nb_elem == 5)
	{
		n_to_push = find_n_edge(&(stacks->a), 2, B_TRUE);
		push_n_smallest_b(stacks, 2, n_to_push, B_TRUE);
		sort_three_elem(&(stacks->a), &(stacks->b), B_TRUE);
		if (stacks->b->start->nb < stacks->b->end->nb)
			swap_b(&(stacks->a), &(stacks->b), B_TRUE);
		push_a(&(stacks->a), &(stacks->b), B_TRUE);
		push_a(&(stacks->a), &(stacks->b), B_TRUE);
	}
	else
	{
		n_to_push = find_n_edge(&(stacks->a), 3, B_TRUE);
		push_n_smallest_b(stacks, 3, n_to_push, B_TRUE);
		sort_three_elem(&(stacks->a), &(stacks->b), B_TRUE);
		sort_three_elem(&(stacks->b), &(stacks->b), B_FALSE);
		push_a(&(stacks->a), &(stacks->b), B_TRUE);
		push_a(&(stacks->a), &(stacks->b), B_TRUE);
		push_a(&(stacks->a), &(stacks->b), B_TRUE);
	}
}

void				small_list(t_stacks *stacks, size_t nb_elem)
{
	int				n_to_push;

	if (nb_elem == 2)
		swap_a(&(stacks->a), &(stacks->b), B_TRUE);
	else if (nb_elem == 3)
		sort_three_elem(&(stacks->a), &(stacks->b), B_TRUE);
	else if (nb_elem == 4)
	{
		n_to_push = find_n_edge(&(stacks->a), 1, B_TRUE);
		push_n_smallest_b(stacks, 1, n_to_push, B_TRUE);
		sort_three_elem(&(stacks->a), &(stacks->b), B_TRUE);
		push_a(&(stacks->a), &(stacks->b), B_TRUE);
	}
	else
		moar_small_lists(stacks, nb_elem);
}
