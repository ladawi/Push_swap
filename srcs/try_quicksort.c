/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_quicksort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:07:20 by ladawi            #+#    #+#             */
/*   Updated: 2021/12/17 22:10:22 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

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
	int	nbone;
	int	nbtwo;
	int	tmp;
	int	nb_ini;

	if (i < 0 || j > data->lenght_list_a)
		return ;
	nbone = data->list_a[i];
	nbtwo = data->list_a[j];
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
}

int	partition(t_data *data, int start, int end, int *tab)
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
}

void	try_quicksort(t_data *data, int start, int end, int depth)
{
	int	i;
	int	pivot;

	depth++;
	if (start >= 0 && end >= 0 && start < end)
	{
		pivot = partition(data, start, end, data->list_a);
		try_quicksort(data, start, pivot, depth);
		try_quicksort(data, pivot + 1, end, depth);
	}
}
