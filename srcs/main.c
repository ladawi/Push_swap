/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:47:39 by ladawi            #+#    #+#             */
/*   Updated: 2021/09/13 15:52:08 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void	print_list(t_push_swap *push_swap, t_chain *node)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	printf("\033[0;34m[>%p< | >nb = %d<]\033[0m\n", node, node->nb);
	if (node->prev != NULL)
		print_list(push_swap, node->prev);
	return ;
}

t_chain		*set_list_tail(t_push_swap *push_swap, t_chain *node)
{
	if (node->prev == NULL)
		return (node);
	return (set_list_tail(push_swap, node->prev));
}

int			main(int ac, char **av)
{
	t_push_swap	push_swap;

	ft_bzero(&push_swap, sizeof(push_swap));
	push_swap.len = ac - 1;
	push_swap.tab_nb = ft_calloc(sizeof(int *), push_swap.len);
	if (!(push_swap.tab_nb))
		return (-1);
	get_list(&push_swap, ac - 1, av);
	push_swap.list_a_tail = set_list_tail(&push_swap, push_swap.list_a);
	// printf("::%p::\n", push_swap.list_a_tail);
	if (check(ac, av) || check_double(&push_swap, 0, ac - 1))
	{
		ft_putendl_fd("Error input", 0);
		return (-1);
	}
	get_median(&push_swap);
	print_list(&push_swap, push_swap.list_a);
	rotate_a(&push_swap);
	printf("------------------------\n");
	print_list(&push_swap, push_swap.list_a);
	printf("------------------------\n");
	swap_a(&push_swap);
	print_list(&push_swap, push_swap.list_a);
	return (0);
}