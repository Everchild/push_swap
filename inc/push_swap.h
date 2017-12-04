/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:04:35 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/04 18:38:21 by sbrochar         ###   ########.fr       */
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
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_elem;

typedef struct		s_stack
{
	t_elem			*start;
	t_elem			*elem;
}					t_stack;

typedef struct		s_stacks
{
	t_stack			*a;
	t_stack			*b;
}

typedef struct		s_instr
{
	char			*str;
	void			(*instr)(t_stack **, t_stack **, t_bool);
}					t_instr;

#endif PUSH_SWAP_H
