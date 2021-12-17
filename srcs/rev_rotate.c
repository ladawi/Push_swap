/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:59:04 by ladawi            #+#    #+#             */
/*   Updated: 2021/12/17 22:21:23 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

int	rev_rotate_a(t_data *data)
{
	int		nb;
	int		x;
	int		i;

	i = data->lenght_list_a - 1;
	nb = data->list_a[data->lenght_list_a - 1];
	if (data->lenght_list_a > 1)
	{
		while (i > 0)
		{
			data->list_a[i] = data->list_a[i - 1];
			i--;
		}
		data->list_a[0] = nb;
	}
	return (0);
}

int	rev_rotate_b(t_data *data)
{
	int		nb;
	int		x;
	int		i;

	i = data->lenght_list_b - 1;
	nb = data->list_b[data->lenght_list_b - 1];
	if (data->lenght_list_b > 1)
	{
		while (i > 0)
		{
			data->list_b[i] = data->list_b[i - 1];
			i--;
		}
		data->list_b[0] = nb;
	}
	return (0);
}

int	rev_rotate_rr(t_data *data)
{
	rev_rotate_a(data);
	rev_rotate_b(data);
	return (0);
}
