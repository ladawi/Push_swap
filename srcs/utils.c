/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:00:20 by ladawi            #+#    #+#             */
/*   Updated: 2021/12/09 14:01:49 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

int	find_min(t_data *data)
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

int	find_max(t_data *data)
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
