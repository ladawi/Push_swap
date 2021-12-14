/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:56:19 by ladawi            #+#    #+#             */
/*   Updated: 2021/12/14 16:07:07 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void	rotate_tab(int *tab, int len)
{
	int tmp;
	int i;

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

int		get_nb_move_tostart(int *tab, int len_tab, int nb)
{
	int i;

	i = 0;
	while (tab[i] != nb && i < len_tab)
		i++;
	if (i >= len_tab)
		return (-1);
	else if (i > (int)(len_tab) / 2)
		i = -i + len_tab;
	return (i);
}

int		get_nb_move_insert(int *tab, int len_tab, int nb)
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

void	get_list_simu(t_data *data)
{
	int i;

	i = 0;
	data->lenght_list_simu = data->lenght_list_b;
	while (i < data->lenght_list_b)
	{
		data->list_simu[i] = data->list_b[i];
		i++;
	}
}

void	rem_nb_from_simu(t_data *data, int nb)
{
	int	i;

	i = 0;
	while (data->list_simu[0] != nb && i < data->lenght_list_simu)
	{
		rotate_tab(data->list_simu, data->lenght_list_simu);
		i++;
	}
	rotate_tab(data->list_simu, data->lenght_list_simu);
	data->lenght_list_simu--;
}

void	print_simu(t_data *data)
{
	int x = -1;
	printf("\033[0;92m\n");
	while (++x < data->lenght_list_simu)
		printf("(%d)", data->list_simu[x]);
	printf("\033[0m\n");
}

int		next_insert(t_data *data, int *tab, int len_tab)
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
		nb_cost += get_nb_move_insert(data->list_a, data->lenght_list_a, tab[i]);
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
	int	md;

	md = 0;
	pos_nb = ft_find(data, nb, 'b');
	set_nb_to_first_b(data, nb, pos_nb, (int)(data->lenght_list_b / 2));

	md = data->list_a[(int)(data->lenght_list_a /2)];
	while (data->list_a[0] < nb || data->list_a[data->lenght_list_a - 1] > nb)
	{
		if (nb > md)
			exec_stack(data, "rra");
		else
			exec_stack(data, "ra");
	}
	exec_stack(data, "pa");
}

void	go_depth(t_data *data, int depth)
{
	int	i;

	i = 0;
	getchar();
	printf("\033[0;91mDoc arrive %d || %ld\033[0m\n", depth , data->lenght_list_simu);
	print_simu(data);
	if (data->lenght_list_simu < 2)
	{
		printf("\033[0;91mok done\033[0m\n");
		return;
	}
	while (i < data->lenght_list_simu)
	{
		rem_nb_from_simu(data, data->list_simu[i]);
		go_depth(data, depth + 1);
		get_list_simu(data);
		i++;
	}
}

void	big_sort(t_data *data)
{
	int	min;
	int	max;
	int	*nb_order;
	int	x;
	int	y;

	y = 0;
	nb_order = ft_calloc(data->lenght_list_b + data->lenght_list_a, sizeof(int));
	if (!(nb_order))
		return ;
	x = 0;
	min = data->list_a[find_min(data)];
	max = data->list_a[find_max(data)];
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
	get_list_simu(data);
	

	go_depth(data, 0);
	// while (data->lenght_list_simu > 1)
	// {
	// 	nb_order[x] = next_insert(data, data->list_simu, data->lenght_list_simu);
	// 	rem_nb_from_simu(data, nb_order[x]);
	// 	x++;
	// }
	
	
	while(y < x)
	{
		insert_nb_in_lista(data, nb_order[y]);
		y++;
	}
	// insert_nb_in_lista(data, data->list_b[0]);
	// set_pos_list(data);
	// PRINT
	int i = 0;
	while (i < x)
	{
		printf("\033[0;95m~%d~\033[0m\n", nb_order[i]);
		i++;
	}
	print_simu(data);
	print_list(data);


	free(nb_order);
}