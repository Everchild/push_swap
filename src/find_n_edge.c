/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_n_edge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:05:50 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/08 03:22:05 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void			insert_biggest_node(t_stack **n_edge, int i, size_t n)
{
	t_elem			*node;
	t_elem			*cur;

	cur = (*n_edge)->start;
	node = ps_create_elem(i);
	if (node)
	{
		while (cur && cur != (*n_edge)->end && node->nb < cur->nb)
			cur = cur->next;
		if (cur != (*n_edge)->end || (cur == (*n_edge)->end && node->nb > cur->nb))
			ps_insert_elem(n_edge, node, cur);
		else if (node->nb < cur->nb && (*n_edge)->nb_elems < n)
			ps_add_end(n_edge, node);
		if ((*n_edge)->nb_elems > n)
			ps_remove_node(n_edge, &(*n_edge)->end);
	}
}
#include <stdlib.h>
static void			insert_smallest_node(t_stack **n_edge, int i, size_t n)
{
	t_elem			*node;
	t_elem			*cur;
//	t_elem			*to_delete;

	cur = (*n_edge)->start;
	node = ps_create_elem(i);
	printf("node : %p | value %d\n", node, node->nb);
	if (node)
	{
		if (!cur)
			ps_add_end(n_edge, node);
		else
		{
			while (cur && cur != (*n_edge)->end && i > cur->nb)
				cur = cur->next;
			if (cur != (*n_edge)->end || (cur == (*n_edge)->end && i < cur->nb))
				ps_insert_elem(n_edge, node, cur);
			else if (node->nb > cur->nb && (*n_edge)->nb_elems < n)
				ps_add_end(n_edge, node);
			else
				ft_memdel((void **)&node);
			if ((*n_edge)->nb_elems > n)
			{
	//			to_delete = (*n_edge)->end;
	//			printf("todel : %p\n", to_delete);
				ps_remove_node(n_edge, &(*n_edge)->end);
			}
		}
	}
}
#include <stdio.h>
int					find_n_edge(t_stack **list, size_t n, t_bool small)
{
	t_stack			*n_edge;
	t_elem			*cur;
	int				ret;

	n_edge = ps_create_list();
	cur = (*list)->start;
	ret = 0;
	if (n_edge)
	{
		while (cur != (*list)->end)
		{
			if (small)
				insert_smallest_node(&n_edge, cur->nb, n);
			else
				insert_biggest_node(&n_edge, cur->nb, n);
			cur = cur->next;
			printf("node : %p | value %d\n", n_edge->start, n_edge->start->nb);
//			getchar();
		}
		if (small)
			insert_smallest_node(&n_edge, cur->nb, n);
		else
			insert_biggest_node(&n_edge, cur->nb, n);
	}
	ret = n_edge->end->nb;
//	printf("list: %p | start: %p | end: %p\n", n_edge, n_edge->start, n_edge->end);fflush(stdout); // a suppr
	ps_free_list(&n_edge);
//	printf("list: %p\n", n_edge);fflush(stdout); // a suppr
	return (ret);
}
