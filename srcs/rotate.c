/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:13:51 by ladawi            #+#    #+#             */
/*   Updated: 2021/12/17 22:51:46 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

int	rotate_a(t_data *data)
{
	int		nb;
	int		i;

	i = 0;
	nb = data->list_a[0];
	if (data->lenght_list_a > 1)
	{
		while (i < data->lenght_list_a - 1)
		{
			data->list_a[i] = data->list_a[i + 1];
			i++;
		}
		data->list_a[data->lenght_list_a - 1] = nb;
	}
	return (0);
}

int	rotate_b(t_data *data)
{
	int		nb;
	int		i;

	i = 0;
	nb = data->list_b[0];
	if (data->lenght_list_b > 1)
	{
		while (i < data->lenght_list_b - 1)
		{
			data->list_b[i] = data->list_b[i + 1];
			i++;
		}
		data->list_b[data->lenght_list_b - 1] = nb;
	}
	return (0);
}

int	rotate_rr(t_data *data)
{
	rotate_a(data);
	rotate_b(data);
	return (0);
}
