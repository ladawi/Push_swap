/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:21:05 by ladawi            #+#    #+#             */
/*   Updated: 2021/12/17 22:20:49 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void	mini_sort(t_data *data)
{
	int	pos_max;
	int	pos_min;

	pos_max = find_max_a(data);
	pos_min = find_min_a(data);
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

void	small_sort(t_data *data, int ac)
{
	int	pos_min;
	int	pos_max;
	int	max;
	int	min;

	pos_min = find_min_a(data);
	pos_max = find_max_a(data);
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

void	sort_pars(t_data *data, int ac)
{
	if (ac <= 4)
	{
		mini_sort(data);
	}
	else if (ac <= 6)
	{
		small_sort(data, ac);
	}
	else
	{
		big_sort(data);
	}
}
