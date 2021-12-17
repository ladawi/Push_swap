/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:56:19 by ladawi            #+#    #+#             */
/*   Updated: 2021/12/17 22:39:35 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

int	next_insert(t_data *data, int *tab, int len_tab)
{
	int	i;
	int	nb_cost;
	int	best_cost;
	int	best_nb;

	i = 0;
	best_cost = data->lenght_list_a + data->lenght_list_b;
	while (i < len_tab)
	{
		nb_cost = get_nb_move_tostart(tab, len_tab, tab[i]);
		nb_cost += get_nb_move_insert(data->list_simu_a,
				data->lenght_list_simu_a, tab[i]);
		if (best_cost > nb_cost)
		{
			best_cost = nb_cost;
			best_nb = tab[i];
		}
		i++;
	}
	return (best_nb);
}

void	insert_nb_in_lista(t_data *data, int nb)
{
	int	pos_nb;

	pos_nb = ft_find(data, nb, 'b');
	set_nb_to_first_b(data, nb, pos_nb, (int)(data->lenght_list_b / 2));
	while (data->list_a[0] < nb || data->list_a[data->lenght_list_a - 1] > nb)
	{
		if (data->list_a[0] > nb)
			exec_stack(data, "rra");
		else
			exec_stack(data, "ra");
	}
	exec_stack(data, "pa");
}

void	big_sort_set_list_a(t_data *data)
{
	int	min;
	int	max;

	min = data->list_a[find_min_a(data)];
	max = data->list_a[find_max_a(data)];
	while (data->lenght_list_a > 5)
	{
		if (data->list_a[0] != min && data->list_a[0] != max)
		{
			exec_stack(data, "pb");
			if (data->list_b[0] > data->mediane)
				exec_stack(data, "rb");
		}
		else
			exec_stack(data, "ra");
	}
	small_sort(data, 6);
	get_list_simu_b(data);
	get_list_simu_a(data);
}

void	big_sort(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	big_sort_set_list_a(data);
	while (data->lenght_list_simu_b > 1)
	{
		data->nb_order[x] = next_insert(data, data->list_simu_b,
				data->lenght_list_simu_b);
		rem_nb_from_simu(data, data->nb_order[x]);
		add_nb_in_simu_a(data, data->nb_order[x]);
		x++;
	}
	while (y < x)
		insert_nb_in_lista(data, data->nb_order[y++]);
	insert_nb_in_lista(data, data->list_b[0]);
	set_pos_list(data);
}
