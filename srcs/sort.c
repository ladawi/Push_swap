/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:21:05 by ladawi            #+#    #+#             */
/*   Updated: 2021/12/08 16:49:50 by ladawi           ###   ########.fr       */
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
		if (min > data->list_a[i])
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
		if (max < data->list_a[i])
		{
			pos_max = i;
			max = data->list_a[i];
		}
		i++;
	}
	return (pos_max);
}

void	send_min(t_data *data, int rotate_num)
{
	int	i;

	i = 0;
	while (rotate_num-- > 0)
	{
		rotate_a(data);
	}
	push_b(data);
}

void			selec_sort(t_data *data)
{
	int		i;
	int		x;

	i = 0;
	while (data->lenght_list_a > 1)
	{
		x = find_min(data);
		send_min(data, x);
		i++;
	}
	while (i-- > 0)
		push_a(data);
	rotate_a(data);
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

void	mini_sort(t_data *data)
{
	int	pos_max;
	int	pos_min;

	pos_max = find_max(data);
	pos_min = find_min(data);
	if (pos_max == 2 && pos_min == 1)
		exec_stack(data, "sa");
	else if (pos_max == 0 && pos_min == 2)
	{
		exec_stack(data, "sa");
		exec_stack(data, "rra");
	}
	else if (pos_max == 0 && pos_min == 1)
		exec_stack(data, "ra");
	else if (pos_max == 1 && pos_min == 0)
	{
		exec_stack(data, "sa");
		exec_stack(data, "ra");
	}
	else if (pos_max == 1 && pos_min == 2)
		exec_stack(data, "rra");
}

void	small_sort(t_data *data)
{
	int	pos_min;

	exec_stack(data, "pb");
	// exec_stack(data, "pb");
	// if (data->list_b[0] > data->list_b[1])
		// exec_stack(data, "sb");
	mini_sort(data);
	// exec_stack(data, "rra");
	// exec_stack(data, "rra");
	// while (data->list_a[data->lenght_list_a - 1] > data->list_b[0] && data->list_a[0] < data->list_b[0])
	// 	exec_stack(data, "ra");
	// exec_stack(data, "pa");
	// // pos_min = find_min(data);
	// while (find_min(data) != 0)
	// {
	// 	if (pos_min > (int)(data->lenght_list_a / 2))
	// 		exec_stack(data, "ra");
	// 	else
	// 		exec_stack(data, "rra");
	// }
		// exec_stack(data, "rra");
	// printf("-= min = %d =-\n", find_min(data));

	// if (data->list_b[0] > data->list_a[2])
	
}

void		sort(t_data *data, int ac)
{
	// if (ac > 4)
	// {
	// 	quick_sort(data, 0, data->lenght_list_a - 1);
	// 	printf("__ QUICK SORT __\n");
	// }
	// else
	// {
		if (ac <= 4)
		{
			mini_sort(data);
		}
		else if (ac <= 6)
		{
			small_sort(data);
		}
		else if (ac <= 7)
		{
			// small_sort(data);
			// exec_stack(data, "sa");
			// exec_stack(data, "pb");
			// exec_stack(data, "pb");
			// exec_stack(data, "pb");
			// exec_stack(data, "rr");
			// exec_stack(data, "rrr");
			// exec_stack(data, "sa");
			// exec_stack(data, "pa");
			// exec_stack(data, "pa");
			// exec_stack(data, "pa");

		}
		// else
		// 	selec_sort(data);
	// }
}