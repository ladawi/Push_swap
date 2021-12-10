/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selec_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:07:27 by ladawi            #+#    #+#             */
/*   Updated: 2021/12/10 19:20:58 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"


void			insertion_sort(t_data *data)
{
	int		i;
	int		x;
	int		mid;
	int		min;

	i = 2;
	mid = data->list_a[(int)(data->lenght_list_a/2)];
	x = find_min(data);
	min = data->list_a[x];
	set_nb_to_first(data, data->list_a[x], x, (data->lenght_list_a / 2));
	exec_stack(data, "pb");
	x = find_max(data);
	set_nb_to_first(data, data->list_a[x], x, (data->lenght_list_a / 2));
	exec_stack(data, "pb");
	while(data->lenght_list_a > 0)
	{
		if(data->list_b[0] < data->list_a[0] && data->list_b[data->lenght_list_b - 1] > data->list_a[0])
		{
			exec_stack(data, "pb");
			i++;
		}
		else if (data->list_a[0] < mid)
			exec_stack(data, "rb");
		else
			exec_stack(data, "rrb");
	}
	while (i-- > 0)
		exec_stack(data, "pa");
	set_pos_list(data);
}

void			selec_sort(t_data *data)
{
	int		i;
	int		x;

	i = 1;
	// x = find_min(data);
	// set_nb_to_first(data, data->list_a[x], x, (data->lenght_list_a / 2));
	// exec_stack(data, "pb");
	while (data->lenght_list_a > 1)
	{
		x = find_min(data);
		set_nb_to_first(data, data->list_a[x], x, (data->lenght_list_a / 2));
		exec_stack(data, "pb");
		i++;
	}
	while (i-- > 0)
		exec_stack(data, "pa");
	// set_pos_list(data);
}
