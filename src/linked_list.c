/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:56:08 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/05 19:18:21 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				ft_memdel((void **)&cur);
				cur = next;
			}
			cur->prev = NULL;
			cur->next = NULL;
			ft_memdel((void **)&cur);
		}
		ft_memdel((void **)list);
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
