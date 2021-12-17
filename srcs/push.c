/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:10:00 by ladawi            #+#    #+#             */
/*   Updated: 2021/12/17 22:54:21 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

int	push_a(t_data *data)
{
	if (data->lenght_list_b > 0)
	{
		data->list_a[data->lenght_list_a] = data->list_b[0];
		rotate_b(data);
		data->lenght_list_a++;
		data->lenght_list_b--;
		rev_rotate_a(data);
	}
	return (0);
}

int	push_b(t_data *data)
{
	if (data->lenght_list_a > 0)
	{
		data->list_b[data->lenght_list_b] = data->list_a[0];
		rotate_a(data);
		data->lenght_list_b++;
		data->lenght_list_a--;
		rev_rotate_b(data);
	}
	return (0);
}
