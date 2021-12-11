/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:21:05 by ladawi            #+#    #+#             */
/*   Updated: 2021/12/11 14:37:13 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

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

void	set_pos_list(t_data *data)
{
	int	pos_min;

	pos_min = find_min(data);
	while (find_min(data) != 0)
	{
		if (pos_min < (int)(data->lenght_list_a / 2))
			exec_stack(data, "ra");
		else
			exec_stack(data, "rra");
	}
}

void	place_listb_nb(t_data *data)
{
	if (data->list_b[0] < data->list_a[find_min(data)] || data->list_b[0] > data->list_a[find_max(data)])
	{
		set_pos_list(data);
		exec_stack(data, "pa");
	}
	else
	{
		while (data->list_a[data->lenght_list_a - 1] > data->list_b[0] || data->list_a[0] < data->list_b[0])
			exec_stack(data, "ra");
		exec_stack(data, "pa");
	}
}

void	small_sort(t_data *data, int ac)
{
	int	pos_min;
	int pos_max;
	int	max;
	int min;

	pos_min = find_min(data);
	pos_max = find_max(data);
	max = data->list_a[pos_max];
	min = data->list_a[pos_min];
	exec_stack(data, "pb");
	if (ac == 6)
		exec_stack(data, "pb");
	mini_sort(data);
	place_listb_nb(data);
	place_listb_nb(data);
	set_pos_list(data);
}

void		sort_pars(t_data *data, int ac)
{
	if (ac <= 4)
	{
		mini_sort(data);
	}
	else if (ac <= 6)
	{
		small_sort(data, ac);
	}
	// else if (ac <= 90)
	// {
	// 	selec_sort(data);
	// 	// insertion_sort(data);
	// }
	else
		{
			big_sort(data);
		// selec_sort(data);
			// try_quicksort(data, 0, data->lenght_list_a);
			// get_midiane_n(data, 0, data->lenght_list_a);
			// printf("\033[93mMEDIANE = %d\033[0m\n", data->mediane);
			// try_quicksort(data, 0, data->lenght_list_a - 1, 0);
			// exec_stack(data, "ra");
		}
		// swap(data, 0, 4);
}