/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:21:05 by ladawi            #+#    #+#             */
/*   Updated: 2021/05/26 14:20:27 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"


void			set_max(t_data *data)
{
	int		max;

	max = 0;
	max = get_max(data);
	while (data->list_a[data->lenght_list_a - 1] != max)
	{
		if (data->index_max > (size_t)(data->lenght_list_a / 2))
			rev_rotate_a(data);
		else
			rotate_a(data);
	}
}

void			simple_sort(t_data *data)
{
	int		i;
	int		x;

	i = 0;
	// set_max(data);
	if (data->list_a[0] > data->list_a[1])
		swap_a(data);
	if (data->lenght_list_a > 3)
	{
		while (i <= data->lenght_list_a)
		{
			if (data->list_a[0] > data->mediane)
				push_b(data);
			else
			{
				rotate_a(data);
			}
			i++;
		}
		i = 0;
	}
	while (data->list_a[data->lenght_list_a - 1] != get_max(data))
	{
		rotate_a(data);
	}
	while (i < data->lenght_list_a - 1)
	{
		if (data->list_a[i] >= data->list_a[i + 1])
		{
			x = i;
			while (x > 0)
			{
				rotate_a(data);
				x--;
			}
			swap_a(data);
			while (x++ < i)
			{
				rev_rotate_a(data);
			}
			i = 0;
			// i = -1;
			// while (++i < data->lenght_list_a)
			// 	printf("[%d]", data->list_a[i]);
			// printf("\n");
			// i = 0;
		}
		else
			i++;
	}
	while (data->lenght_list_b)
	{
		push_a(data);
	}
}

void			swap(t_data *data, int x, int y)
{
	int		i;

	i = 0;
	if (y < data->lenght_list_a && x < y)
	{
		while (i++ < x)
			rotate_a(data);
		push_b(data);
		while (i++ < y)
			rotate_a(data);
		push_b(data);
		push_a(data);
		while (--i > x)
			rev_rotate_a(data);
		push_a(data);
		while (i-- >= 0)
			rev_rotate_a(data);
	}
	else if (x > y && x < data->lenght_list_a)
	{
		while (i++ < y)
			rotate_a(data);
		push_b(data);
		while (i++ < x)
			rotate_a(data);
		push_b(data);
		push_a(data);
		while (--i > y)
			rev_rotate_a(data);
		push_a(data);
		while (i-- >= 0)
			rev_rotate_a(data);
	}
}

void			quick_sort(t_data *data, int first, int last)
{
	int		i;
	int		j;
	int		pivot;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (data->list_a[i] <= data->list_a[pivot] && i < last)
				i++;
			while (data->list_a[j] > data->list_a[pivot])
				j--;
			if (i < j)
			{
				swap(data, i, j);
			}
		}
		swap(data, pivot, j);
		quick_sort(data, j + 1, last);
		quick_sort(data, first, j - 1);
	}
}


void		sort(t_data *data, int ac)
{
	if (ac > 10)
	{
		quick_sort(data, 0, data->lenght_list_a - 1);
		printf("__ QUICK SORT __\n");
	}
	else
		simple_sort(data);
}