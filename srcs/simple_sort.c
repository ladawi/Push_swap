/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:21:05 by ladawi            #+#    #+#             */
/*   Updated: 2021/05/24 15:29:24 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

int			simple_sort(t_data *data)
{
	int		i;
	int		x;

	x = 0;
	i = 0;
	while (i < data->lenght_list_a)
	{
		if (data->list_a[0] < data->list_a[1])
		{
			rotate_a(data);
			i++;
		}
		else
		{
			printf("swap\n");
			printf("{%d  | %d}\n", data->list_a[0], data->list_a[1]);
			swap_a(data);
			// i = 0;
		}
	}
	return (0);
}