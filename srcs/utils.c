/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:13:14 by ladawi            #+#    #+#             */
/*   Updated: 2022/01/16 15:57:50 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

int	set_nb_to_first_a(t_data *data, int nb, int pos_nb, int median)
{
	int	c;

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
	int	c;

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

void	set_pos_list(t_data *data)
{
	int	pos_min;

	pos_min = find_min_a(data);
	while (find_min_a(data) != 0)
	{
		if (pos_min < (int)(data->lenght_list_a / 2))
			exec_stack(data, "ra");
		else
			exec_stack(data, "rra");
	}
}

void	place_listb_nb(t_data *data)
{
	if (data->list_b[0] < data->list_a[find_min_a(data)]
		|| data->list_b[0] > data->list_a[find_max_a(data)])
	{
		set_pos_list(data);
		exec_stack(data, "pa");
	}
	else
	{
		while (data->list_a[data->lenght_list_a - 1] > data->list_b[0]
			|| data->list_a[0] < data->list_b[0])
			exec_stack(data, "ra");
		exec_stack(data, "pa");
	}
}
