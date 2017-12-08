/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:56:08 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/08 01:03:17 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <push_swap.h>

void				ps_free_list(t_stack **list)
{
	t_elem			*cur;
	t_elem			*next;

	if (list && *list)
	{
		cur = (*list)->start;
		next = NULL;
		if (cur)
		{
			while (cur != (*list)->end)
			{
				next = cur->next;
				cur->prev = NULL;
				cur->next = NULL;
				free(cur);
				cur = NULL;
				cur = next;
			}
			cur->prev = NULL;
			cur->next = NULL;
			free(cur);
			cur = NULL;
		}
		(*list)->start = NULL;
		(*list)->end = NULL;
		free(*list);
		*list = NULL;
	}
}

void				ps_remove_node(t_stack **list, t_elem **node)
{
	t_elem			*to_delete;

	if (list && *list && node && *node)
	{
		to_delete = *node;
		if ((*list)->nb_elems > 1)
		{
			if (to_delete == (*list)->start)
				(*list)->start = to_delete->next;
			if (to_delete == (*list)->end)
				(*list)->end = to_delete->prev;
			to_delete->prev->next = to_delete->next;
			to_delete->next->prev = to_delete->prev;
		}
		else
		{
			(*list)->start = NULL;
			(*list)->end = NULL;
		}
		to_delete->prev = NULL;
		to_delete->next = NULL;
		free(to_delete);
		to_delete = NULL;
		(*list)->nb_elems -= 1;
	}
}

t_stack				*ps_create_list(void)
{
	t_stack			*ret;

	ret = (t_stack *)ft_memalloc(sizeof(t_stack));
	if (ret)
	{
		ret->start = NULL;
		ret->end = NULL;
		ret->nb_elems = 0;
		return (ret);
	}
	return (NULL);
}

t_elem				*ps_create_elem(int nb)
{
	t_elem			*ret;

	ret = (t_elem *)ft_memalloc(sizeof(t_elem));
	if (ret)
	{
		ret->nb = nb;
		ret->prev = NULL;
		ret->next = NULL;
		return (ret);
	}
	return (NULL);
}

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
