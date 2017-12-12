/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:44:31 by sbrochar          #+#    #+#             */
/*   Updated: 2017/12/12 14:29:58 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int					main(int argc, char **argv)
{
	size_t			nb_elem;
	t_stacks		stacks;

	nb_elem = 0;
	stacks.a = NULL;
	stacks.b = ps_create_list();
	if (argc <= 1)
		ft_printf("usage: ./push_swap <nb1> <nb2> <...>\n");
	else
	{
		if (!parsing_args(&nb_elem, &(stacks.a), argv + 1) || !(stacks.b))
			ft_printf("Error\n");
		else
			choose_algo(&stacks, nb_elem);
	}
	if (stacks.a)
		ps_free_list(&(stacks.a));
	if (stacks.b)
		ps_free_list(&(stacks.b));
	return (0);
}
