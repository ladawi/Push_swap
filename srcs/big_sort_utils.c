/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:34:33 by ladawi            #+#    #+#             */
/*   Updated: 2021/12/17 22:40:30 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void	rotate_tab(int *tab, int len)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = tab[0];
	while (i < len - 1)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i] = tmp;
	i = 0;
}

int	get_nb_move_tostart(int *tab, int len_tab, int nb)
{
	int	i;

	i = 0;
	while (tab[i] != nb && i < len_tab)
		i++;
	if (i >= len_tab)
		return (-1);
	else if (i > (int)(len_tab) / 2)
		i = -i + len_tab;
	return (i);
}

int	get_nb_move_insert(int *tab, int len_tab, int nb)
{
	int	i;

	i = 0;
	while (tab[i] < nb && i < len_tab)
	{
		i++;
	}
	if (i >= len_tab)
		return (-1);
	else if (i > (int)(len_tab) / 2)
		i = -i + len_tab;
	return (i);
}
