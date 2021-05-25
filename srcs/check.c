/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:48:37 by ladawi            #+#    #+#             */
/*   Updated: 2021/05/25 16:41:46 by ladawi           ###   ########.fr       */
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
		if (x > 10)
			return(-1);
		x = 0;
	}
	return (0);
}

int			check_double(t_data *data, int index)
{
	int		i;
	int		nb;
	
	if (index > data->lenght_list_a - 1)
		return (0);
	nb = data->list_a[index];
	i = 0;
	while (i < data->lenght_list_a)
	{
		if (nb == data->list_a[i] && i != index)
			return (-1);
		i++;
	}
	return(check_double(data, index + 1));
}

int			is_int(t_data *data)
{
	int		i;

	i = 0;
	return (0);
}