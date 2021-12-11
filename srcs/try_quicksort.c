/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_quicksort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:07:20 by ladawi            #+#    #+#             */
/*   Updated: 2021/12/11 17:28:33 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

int		ft_find(t_data *data, int nb, char list)
{
	int	i;

	i = -1;
	if (list == 'a')
	{
		while (++i < data->lenght_list_a)
		{
			if (data->list_a[i] == nb)
				return (i);
		}
	}
	else if (list == 'b')
	{
		while (++i < data->lenght_list_b)
		{
			if (data->list_b[i] == nb)
				return (i);
		}
	}
	else if (list == 's')
	{
		while (++i < data->lenght_list_simu)
		{
			if (data->list_simu[i] == nb)
				return (i);
		}
	}
}

void	go_checkpoint(t_data *data, int nb)
{
	while (nb != 0)
	{
		if (nb < 0)
		{
			exec_stack(data, "rra");
			nb++;
		}
		else if (nb > 0)
		{
			exec_stack(data, "ra");
			nb--;
		}
	}
}

void	ft_swap(t_data *data, int i, int j, int median)
{
	int nbone;
	int	nbtwo;
	int tmp;
	int	nb_ini;

	if (i < 0 || j > data->lenght_list_a)
		return;
	nbone = data->list_a[i];
	nbtwo = data->list_a[j];
	// printf("__ %d __ %d ___\n", nbone, nbtwo);
	nb_ini = data->list_a[0];
	nb_ini = set_nb_to_first_a(data, nbone, i, median);
	exec_stack(data, "pb");
	tmp = set_nb_to_first_a(data, nbtwo, ft_find(data, nbtwo, 'a'), median);
	exec_stack(data, "pb");
	exec_stack(data, "sb");
	exec_stack(data, "pa");
	go_checkpoint(data, tmp);
	exec_stack(data, "pa");
	go_checkpoint(data, nb_ini);
	// set_nb_to_first(data, nb_ini, ft_find(data, nb_ini), median);
}
	// printf("median = %d, tmp = %d\n", median, tmp);

int		partition(t_data *data, int start, int end, int *tab)
{
	int		p;
	int		j;
	int		i;
	int		tmp;
	int		mid;

	tmp = 0;
	i = 0;
	j = 0;
	mid = (int)((start + end) / 2);
	p = tab[mid];
	i = start - 1;
	j = end + 1;
	while (1)
	{
		i++;
		while (tab[i] < p)
			i++;
		j--;
		while (tab[j] > p)
			j--;
		if (i >= j)
			return (j);
		ft_swap(data, i, j, mid);
	}
	// return (i);
}

void	try_quicksort(t_data *data, int start, int end, int depth)
{
	int	i;
	int pivot;

	depth++;


	// i = 0;
	// if (start < 0 || start >= end)
	// 	return ;
	// pivot = 0;
	// get_midiane_n(data, start, end);
	// printf("__[%d]__\n", data->mediane);
	// getchar();
	// i = -1;
	// while (++i < data->lenght_list_a)
	// 	printf("[%d]\n", data->list_a[i]);
	if (start >= 0 && end >= 0 && start < end)
	{
		// if (end - start <= 90)
		// {
		// 	// if (data->selec_sort_done == 0)
		// 	// {
		// 		selec_sort(data);
		// 	// 	data->selec_sort_done == 1;
		// 	// }
		// }
		// else
		// {
			pivot = partition(data, start, end, data->list_a);
			try_quicksort(data, start, pivot, depth);
			try_quicksort(data, pivot + 1, end, depth);
		// }
	}

	// printf("\033[0;91m___ pivot = %d ___ end = %d __ start = %d ___ | depth = %d.\033[0m\n", pivot, end, start, depth);
}
