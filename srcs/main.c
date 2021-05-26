/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:47:39 by ladawi            #+#    #+#             */
/*   Updated: 2021/05/26 13:52:34 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

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
	printf("MEDIANE = %d\n", data.mediane);
	sort(&data, ac);
	printf("### %d ###\n", data.count);
	int i = -1;
	while (++i < data.lenght_list_a)
		printf("[%d]\n", data.list_a[i]);
	i = -1;
	while (++i < data.lenght_list_b)
		printf("{%d}\n", data.list_b[i]);
	printf("[lenght a = %ld][lenght b = %ld]\n", data.lenght_list_a, data.lenght_list_b);
	return 0;
}