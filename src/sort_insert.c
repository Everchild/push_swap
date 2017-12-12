/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 21:47:49 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/12 15:31:22 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void			insert(t_elem *cur, t_stack **n_biggest, t_elem *node)
{
	while (cur != (*n_biggest)->end && node->nb < cur->nb)
		cur = cur->next;
	if (cur != (*n_biggest)->end
		|| (cur == (*n_biggest)->end && node->nb > cur->nb))
		ps_insert_elem(n_biggest, node, cur);
	else
		ps_add_end(n_biggest, node);
}

static void			sort_n_biggest(t_stack **n_biggest, t_stack **b, size_t n)
{
	t_elem			*node;
	t_elem			*cur;
	t_elem			*nb_to_sort;

	nb_to_sort = (*b)->start;
	while (n > 0)
	{
		cur = (*n_biggest)->start;
		node = ps_create_elem(nb_to_sort->nb);
		if (node)
		{
			if (!cur)
				ps_add_end(n_biggest, node);
			else
				insert(cur, n_biggest, node);
			n--;
			nb_to_sort = nb_to_sort->next;
		}
	}
}

static void			choose_rotating_way(t_elem **to_find, t_elem *to_push,
					t_bool *rb, t_stack **b)
{
	while ((*to_find)->nb != to_push->nb)
	{
		if (*to_find == (*b)->start)
			*rb = B_TRUE;
		*to_find = (*to_find)->next;
	}
}

static void			find_n_biggest(t_stack **a, t_stack **b,
					t_stack **n_biggest)
{
	t_elem			*to_find;
	t_elem			*to_push;
	t_elem			*save;
	t_bool			rb;

	to_push = (*n_biggest)->start;
	save = (*b)->start;
	while (to_push)
	{
		rb = B_FALSE;
		to_find = save;
		choose_rotating_way(&to_find, to_push, &rb, b);
		if (to_find->nb == save->nb)
			save = save->next;
		while ((*b)->start != to_find)
		{
			if (rb)
				rotate_b(a, b, B_TRUE);
			else
				reverse_rotate_b(a, b, B_TRUE);
		}
		push_a(a, b, B_TRUE);
		ps_remove_node(n_biggest, &to_push);
		to_push = (*n_biggest)->start;
	}
}

void				sort_insert(t_stack **a, t_stack **b, size_t rest, size_t n)
{
	t_stack			*n_biggest;

	n_biggest = ps_create_list();
	if (n_biggest)
	{
		sort_n_biggest(&n_biggest, b, rest);
		find_n_biggest(a, b, &n_biggest);
		while ((*b)->nb_elems)
		{
			sort_n_biggest(&n_biggest, b, n);
			find_n_biggest(a, b, &n_biggest);
		}
		ps_free_list(&n_biggest);
	}
}
