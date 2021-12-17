/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_simu_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:37:11 by ladawi            #+#    #+#             */
/*   Updated: 2021/12/17 22:56:31 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void	get_list_simu_b(t_data *data)
{
	int	i;

	i = 0;
	data->lenght_list_simu_b = data->lenght_list_b;
	while (i < data->lenght_list_b)
	{
		data->list_simu_b[i] = data->list_b[i];
		i++;
	}
}

void	get_list_simu_a(t_data *data)
{
	int	i;

	i = 0;
	data->lenght_list_simu_a = data->lenght_list_a;
	while (i < data->lenght_list_a)
	{
		data->list_simu_a[i] = data->list_a[i];
		i++;
	}
}

void	rem_nb_from_simu(t_data *data, int nb)
{
	int	i;

	i = 0;
	while (data->list_simu_b[0] != nb && i < data->lenght_list_simu_b)
	{
		rotate_tab(data->list_simu_b, data->lenght_list_simu_b);
		i++;
	}
	rotate_tab(data->list_simu_b, data->lenght_list_simu_b);
	data->lenght_list_simu_b--;
}

void	add_nb_in_simu_a(t_data *data, int nb)
{
	while (data->list_simu_a[0] < nb
		|| data->list_simu_a[data->lenght_list_simu_a - 1] > nb)
		rotate_tab(data->list_simu_a, data->lenght_list_simu_a);
	data->list_simu_a[data->lenght_list_simu_a] = nb;
	data->lenght_list_simu_a++;
	while (nb != data->list_simu_a[0])
		rotate_tab(data->list_simu_a, data->lenght_list_simu_a);
}
