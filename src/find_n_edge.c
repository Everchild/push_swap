/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_n_edge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:05:50 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/08 04:16:45 by sbrochar         ###   ########.fr       */
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
		if (!cur)
			ps_add_end(n_edge, node);
		else
		{
			while (cur && cur != (*n_edge)->end && node->nb < cur->nb)
				cur = cur->next;
			if (cur != (*n_edge)->end || (cur == (*n_edge)->end && node->nb > cur->nb))
				ps_insert_elem(n_edge, node, cur);
			else if (node->nb < cur->nb && (*n_edge)->nb_elems < n)
				ps_add_end(n_edge, node);
			else
				ft_memdel((void **)&node);
			if ((*n_edge)->nb_elems > n)
				ps_remove_node(n_edge, &(*n_edge)->end);
		}
	}
}

static void			insert_smallest_node(t_stack **n_edge, int i, size_t n)
{
	t_elem			*node;
	t_elem			*cur;

	cur = (*n_edge)->start;
	node = ps_create_elem(i);
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
				ps_remove_node(n_edge, &(*n_edge)->end);
		}
	}
}

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
		}
		if (small)
			insert_smallest_node(&n_edge, cur->nb, n);
		else
			insert_biggest_node(&n_edge, cur->nb, n);
	}
	ret = n_edge->end->nb;
	ps_free_list(&n_edge);
	return (ret);
}
