/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:04:35 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/08 04:48:19 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

# define NB_INSTR 11
# define PS_OK 1
# define PS_KO 2
# define PS_ERROR 3

typedef struct		s_elem
{
	int				nb;
	struct s_elem	*prev;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_stack
{
	t_elem			*start;
	t_elem			*end;
	size_t			nb_elems;
}					t_stack;

typedef struct		s_stacks
{
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

typedef struct		s_instr
{
	char			*str;
	void			(*instr)(t_stack **, t_stack **, t_bool);
}					t_instr;

void				ps_free_list(t_stack **list);
void				ps_remove_node(t_stack **list, t_elem **node);
t_stack				*ps_create_list(void);
t_elem				*ps_create_elem(int nb);
t_elem				*ps_add_end(t_stack **list, t_elem *node);
t_elem				*ps_add_start(t_stack **list, t_elem *node);
t_elem				*ps_insert_elem(t_stack **list, t_elem *new, t_elem *next);
void				ps_swap_nodes(t_elem **e1, t_elem **e2);

void				swap_a(t_stack **a, t_stack **b, t_bool sort);
void				swap_b(t_stack **a, t_stack **b, t_bool sort);
void				swap_ab(t_stack **a, t_stack **b, t_bool sort);
void				push_a(t_stack **a, t_stack **b, t_bool sort);
void				push_b(t_stack **a, t_stack **b, t_bool sort);
void				rotate_a(t_stack **a, t_stack **b, t_bool sort);
void				rotate_b(t_stack **a, t_stack **b, t_bool sort);
void				rotate_ab(t_stack **a, t_stack **b, t_bool sort);
void				reverse_rotate_a(t_stack **a, t_stack **b, t_bool sort);
void				reverse_rotate_b(t_stack **a, t_stack **b, t_bool sort);
void				reverse_rotate_ab(t_stack **a, t_stack **b, t_bool sort);

t_bool				parsing_args(size_t *nb_elem, t_stack **a, char **args);
void				choose_algo(t_stacks *stacks, size_t nb_elem);
void				small_list(t_stacks *stacks, size_t nb_elem);
int					find_n_edge(t_stack **list, size_t n, t_bool small);
void				push_n_biggest_a(t_stack **a, t_stack **b, size_t n, int n_biggest);
void				push_n_smallest_b(t_stacks *stacks, size_t n, int n_smallest, t_bool first);
void				sort_insert(t_stack **a, t_stack **b, size_t rest, size_t n);

#endif
