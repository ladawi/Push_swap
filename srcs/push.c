/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:10:00 by ladawi            #+#    #+#             */
/*   Updated: 2021/05/24 14:58:36 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

int			push_a(t_data *data)
{
	int		nb;
	int		i;

	i = 0;
	if (data->lenght_list_b > 0)
	{
		data->list_a[data->lenght_list_a] = data->list_b[0];
		rotate_b(data);
		data->lenght_list_a++;
		data->lenght_list_b--;
	}
	return (0);
}

int			push_b(t_data *data)
{
	int		nb;
	int		i;

	i = 0;
	if (data->lenght_list_a > 0)
	{
		data->list_b[data->lenght_list_b] = data->list_a[0];
		rotate_a(data);
		data->lenght_list_b++;
		data->lenght_list_a--;
	}
	return (0);
}
