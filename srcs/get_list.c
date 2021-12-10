/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:04:26 by ladawi            #+#    #+#             */
/*   Updated: 2021/12/09 17:57:20 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

int		get_list(int ac, char **av, t_data *data)
{
	int		i;
	long int nb;

	i = -1;
	if (!(data->list_a = ft_calloc(ac, sizeof(int))))
		return (-1);
	if (!(data->list_b = ft_calloc(ac, sizeof(int))))
		return (-1);
	while (++i < ac)
	{
		nb = ft_atoi(av[i + 1]);
		if ((is_int(data, nb)))
			return (-1);
		data->list_a[i] = nb;
	}
	data->lenght_list_a = ac;
	data->lenght_list_b = 0;
	return (0);
}

int		get_max(t_data *data)
{
	int		i;
	int		nb;
	
	i = 0;
	nb = -2147483647;
	while (i < data->lenght_list_a)
	{
		if (data->list_a[i] > nb)
		{
			nb = data->list_a[i];
			data->index_max = i;
		}
		i++;
	}
	return (nb);
}

void	sort_medianne(t_data *data, int	*tab, int len)
{
	int		i;
	int		buff;

	i = 0;
	while (i < len)
	{
		if (tab[i] > tab[i + 1])
		{
			buff = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = buff;
			i = 0;
		}
		else
			i++;
	}
}

int		get_midiane(t_data *data)
{
	int		i;
	int		tab[data->lenght_list_a];

	i = -1;
	while (++i < data->lenght_list_a)
		tab[i] = data->list_a[i];
	sort_medianne(data, tab, data->lenght_list_a - 1);
	i = 0;
	while (i < (int)(data->lenght_list_a / 2))
		i++;
	data->mediane = tab[i];
	// int	x = -1;
	// while (++x < data->lenght_list_a)
	// 	printf("tab[%d] = %d\n", x, tab[x]);
	// printf("MEDIANE = %d\n", data->mediane);
	return (0);
}

int		get_midiane_n(t_data *data, int start, int end)
{
	int		i;
	int		len;
	int		*tab;

	len = end - start;
	if (len < 0)
		return (-1);
	tab = ft_calloc(len, sizeof(int));
	if (tab == 0)
		return (-1);
	i = -1;
	while (++i + start < end)
		tab[i] = data->list_a[i + start];
	sort_medianne(data, tab, len - 1);
	i = 0;
	while (i < (int)(len / 2))
		i++;
	data->mediane = tab[i];
	// i = -1;
	// while (++i < len)
	// 	printf("{%d}\n", tab[i]);
	// printf("&_ i = %d / tab[i] = %d _&\n", i, tab[i]); 
	free(tab);
	return (0);
}