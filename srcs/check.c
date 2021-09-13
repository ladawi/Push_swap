/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:48:37 by ladawi            #+#    #+#             */
/*   Updated: 2021/09/13 14:42:37 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

int			check(int ac, char **av)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-' || av[i][0] == '+')
			x++;
		while (av[i][x])
		{
			if (!(ft_isdigit(av[i][x])))
				return (-1);
			x++;
		}
		if (x > 11)
			return(-1);
		x = 0;
	}
	return (0);
}

int			check_double(t_push_swap *push_swap, int index, int len)
{
	int		i;
	int		nb;
	
	if (index > len - 1)
		return (0);
	nb = push_swap->tab_nb[index];
	i = 0;
	while (i < len)
	{
		if (nb == push_swap->tab_nb[i] && i != index)
			return (-1);
		i++;
	}
	return(check_double(push_swap, index + 1, len));
}