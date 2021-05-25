/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:21:05 by ladawi            #+#    #+#             */
/*   Updated: 2021/05/25 16:45:22 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

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