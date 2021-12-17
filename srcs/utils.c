/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:00:20 by ladawi            #+#    #+#             */
/*   Updated: 2021/12/17 20:24:47 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

int		ft_find(t_data *data, int nb, char list)
{
	int	i;

	i = -1;
	if (list == 'a')
	{
		while (++i < data->lenght_list_a)
		{
			if (data->list_a[i] == nb)
				return (i);
		}
	}
	else if (list == 'b')
	{
		while (++i < data->lenght_list_b)
		{
			if (data->list_b[i] == nb)
				return (i);
		}
	}
	else if (list == 's')
	{
		while (++i < data->lenght_list_simu)
		{
			if (data->list_simu[i] == nb)
				return (i);
		}
	}
		// printf("\033[0;91m KEKEKEKEKEKEKEK\033[0m\n");
	return (-1);
}

int	find_min_a(t_data *data)
{
	int	i;
	int	pos_min;
	int	min;

	i = 0;
	pos_min = 0;
	min = data->list_a[0];
	while (i < data->lenght_list_a)
	{
		if (min >= data->list_a[i])
		{
			pos_min = i;
			min = data->list_a[i];
		}
		i++;
	}
	return (pos_min);
}

int	find_min_b(t_data *data)
{
	int	i;
	int	pos_min;
	int	min;

	i = 0;
	pos_min = 0;
	min = data->list_b[0];
	while (i < data->lenght_list_b)
	{
		if (min >= data->list_b[i])
		{
			pos_min = i;
			min = data->list_b[i];
		}
		i++;
	}
	return(pos_min);
}

int	find_max_a(t_data *data)
{
	int	i;
	int	pos_max;
	int	max;

	i = 0;
	pos_max = 0;
	max = data->list_a[0];
	while (i < data->lenght_list_a)
	{
		if (max <= data->list_a[i])
		{
			pos_max = i;
			max = data->list_a[i];
		}
		i++;
	}
	return (pos_max);
}

int	find_max_b(t_data *data)
{
	int	i;
	int	pos_max;
	int	max;

	i = 0;
	pos_max = 0;
	max = data->list_b[0];
	while (i < data->lenght_list_b)
	{
		if (max <= data->list_b[i])
		{
			pos_max = i;
			max = data->list_b[i];
		}
		i++;
	}
	return (pos_max);
}

int	set_nb_to_first_a(t_data *data, int nb, int pos_nb, int median)
{
	int c;

	c = 0;
	while (data->list_a[0] != nb)
	{
		c++;
		if (pos_nb < median)
			exec_stack(data, "ra");
		else
			exec_stack(data, "rra");
	}
	if (pos_nb < median)
		c = -c;
	return (c);
}

int	set_nb_to_first_b(t_data *data, int nb, int pos_nb, int pos_median)
{
	int c;

	c = 0;
	while (data->list_b[0] != nb)
	{
		c++;
		if (pos_nb <= pos_median)
			exec_stack(data, "rb");
		else
			exec_stack(data, "rrb");
	}
	if (pos_nb < pos_median)
		c = -c;
	return (c);
}
