/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_n_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 21:40:22 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/07 21:52:48 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_bool		choose_rotating_way(t_stack **list, int n)
{
	size_t			check_r;
	size_t			check_rr;
	t_elem			*cur;

	check_r = 0;
	check_rr = 0;
	cur = (*list)->start;
	while (cur->nb > n)
	{
		cur = cur->next;
		check_r++;
	}
	cur = (*list)->start;
	while (cur->nb > n)
	{
		cur = cur->prev;
		check_rr++;
	}
	return (check_r < check_rr);
}

void				push_n_smallest_b(t_stacks *stacks, size_t n, int n_smallest, t_bool first)
{
	size_t			i;
	t_bool ra;

	i = 0;
	while (i < n)
	{
		if (first)
			ra = 1;
		else
			ra = choose_rotating_way(&stacks->a, n_smallest);
		while (stacks->a->start->nb > n_smallest)
		{
			if (ra)
				rotate_a(&(stacks->a), &(stacks->b), B_TRUE);
			else
				reverse_rotate_a(&(stacks->a), &(stacks->b), B_TRUE);
		}
		push_b(&(stacks->a), &(stacks->b), B_TRUE);
		i++;
	}
}
