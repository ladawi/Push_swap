/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:47:39 by ladawi            #+#    #+#             */
/*   Updated: 2022/01/16 15:51:39 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void	print_list(t_data *data)
{
	int	i;

	i = -1;
	printf("---\n");
	while (++i < data->lenght_list_a)
		printf("[%d]\n", data->list_a[i]);
	i = -1;
	printf("-\n");
	while (++i < data->lenght_list_b)
		printf("{%d}\n", data->list_b[i]);
	printf("---\n");
}

void	print_simu(t_data *data)
{
	int	x;

	x = -1;
	printf("\033[0;92m\n");
	while (++x < data->lenght_list_simu_b)
		printf("(%d)", data->list_simu_b[x]);
	printf("\n");
	x = -1;
	printf("\033[0;95m\n");
	while (++x < data->lenght_list_simu_a)
		printf("(%d)", data->list_simu_a[x]);
	printf("\033[0m\n");
}

void	ft_free(t_data *data)
{
	free(data->list_a);
	free(data->list_b);
	free(data->list_simu_a);
	free(data->list_simu_b);
	free(data->nb_order);
}

int	list_is_sorted(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->lenght_list_a - 1)
	{
		if (data->list_a[i] < data->list_a[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	data.count = 0;
	data.index_max = 0;
	data.mediane = 0;
	if (check(ac, av))
	{
		ft_putendl_fd("Error", 0);
		return (-1);
	}
	if ((get_list(ac - 1, av, &data) != 0) || (check_double(&data, 0)) != 0)
	{
		ft_putendl_fd("Error", 0);
		ft_free(&data);
		return (-1);
	}
	if (ac > 1 && list_is_sorted(&data) == 1)
	{
		get_midiane(&data);
		sort_pars(&data, ac);
	}
	ft_free(&data);
	return (0);
}
