/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:47:39 by ladawi            #+#    #+#             */
/*   Updated: 2021/12/17 22:33:58 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void	print_list(t_data *data)
{
	printf("---\n");
	int i = -1;
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
	int x = -1;
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

int			main(int ac, char **av)
{
	t_data		data;

	data.count = 0;
	data.index_max = 0;
	data.mediane = 0;
	if (check(ac, av))
	{
		ft_putendl_fd("Error 1", 0);
		return(-1);
	}
	if (get_list(ac - 1, av, &data) != 0)
	{
		ft_putendl_fd("Error 2", 0);
		return (-1);
	}
	if (check_double(&data, 0))
	{
		ft_putendl_fd("Error 3", 0);
		return(-1);
	}
	get_midiane(&data);
	sort_pars(&data, ac);
	ft_free(&data);
	// printf("MEDIANE = %d\n", data.mediane);
	// printf("### %d ###\n", data.count);
	return 0;
}