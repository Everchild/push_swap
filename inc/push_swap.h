/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:04:35 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/05 18:18:47 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

# define NB_INSTR 11
# define PS_PK 1
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
t_stack				*ps_create_list(void);
t_elem				*ps_create_elem(int nb);
t_elem				*ps_add_end(t_stack **list, t_elem *node);

t_bool				parsing_args(size_t *nb_elem, t_stack **a, char **args);

#endif
