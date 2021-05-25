/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:04:26 by ladawi            #+#    #+#             */
/*   Updated: 2021/05/25 16:37:22 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

int		get_list(int ac, char **av, t_data *data)
{
	int		i;

	i = -1;
	if (!(data->list_a = ft_calloc(ac, sizeof(int))))
		return (-1);
	if (!(data->list_b = ft_calloc(ac, sizeof(int))))
		return (-1);
	while (++i < ac)
		data->list_a[i] = ft_atoi(av[i + 1]);
	data->lenght_list_a = ac;
	data->lenght_list_b = 0;
	return (0);
}
