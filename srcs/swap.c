/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:00:42 by ladawi            #+#    #+#             */
/*   Updated: 2021/05/26 10:43:42 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

int		swap_a(t_data *data)
{
	int		n;

	if (data->lenght_list_a > 1)
	{
		n = data->list_a[0];
		data->list_a[0] = data->list_a[1];
		data->list_a[1] = n;
		data->count++;
		ft_putendl_fd("sa", 0);
	}
	return (0);
}

int		swap_b(t_data *data)
{
	int		n;

	if (data->lenght_list_b > 1)
	{
		n = data->list_b[0];
		data->list_a[0] = data->list_b[1];
		data->list_b[1] = n;
		data->count++;
		ft_putendl_fd("sb", 0);
	}
	return (0);
}

int		swap_ss(t_data *data)
{
	swap_a(data);
	swap_b(data);
	return (0);
}
