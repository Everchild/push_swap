/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:43:41 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/12 14:44:19 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_elem				*ps_add_end(t_stack **list, t_elem *node)
{
	if (list && *list && node)
	{
		if (!(*list)->start && !(*list)->end)
		{
			(*list)->start = node;
			(*list)->end = node;
			node->prev = (*list)->start;
		}
		else
		{
			node->prev = (*list)->end;
			(*list)->end->next = node;
			(*list)->end = node;
		}
		node->next = (*list)->start;
		(*list)->start->prev = node;
		(*list)->nb_elems += 1;
		return ((*list)->end);
	}
	return (NULL);
}

t_elem				*ps_add_start(t_stack **list, t_elem *node)
{
	if (list && *list && node)
	{
		if (!(*list)->start && !(*list)->end)
		{
			(*list)->start = node;
			(*list)->end = node;
			node->next = (*list)->start;
		}
		else
		{
			node->next = (*list)->start;
			(*list)->start->prev = node;
			(*list)->start = node;
		}
		node->prev = (*list)->end;
		(*list)->end->next = node;
		(*list)->nb_elems += 1;
		return ((*list)->start);
	}
	return (NULL);
}

t_elem				*ps_insert_elem(t_stack **list, t_elem *new, t_elem *next)
{
	if (list && *list && new && next)
	{
		if ((*list)->start == next)
			return (ps_add_start(list, new));
		else
		{
			new->prev = next->prev;
			new->next = next;
			next->prev = new;
			new->prev->next = new;
			(*list)->nb_elems += 1;
			return (new);
		}
	}
	return (NULL);
}

void				ps_swap_nodes(t_elem **e1, t_elem **e2)
{
	int				tmp;

	tmp = (*e1)->nb;
	(*e1)->nb = (*e2)->nb;
	(*e2)->nb = tmp;
}
