/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:56:19 by ladawi            #+#    #+#             */
/*   Updated: 2021/12/11 22:05:53 by ladawi           ###   ########.fr       */
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

int	*ft_get_new_listb(t_data *data, int *tab_old, int len, int nb_to_remove)
{
	int	i;
	int	tmp;

	i = -1;
	while(++i < len - 1)
	{
		data->list_simu[i] = tab_old[i];
	}
	i = 0;
	// ft_putendl_fd("MUKMUKMUK", 1);
	// printf("\033[93m stuck | %d // len = %d\033[0m\n", nb_to_remove, *len);
	// int x = -1;
	// while (++x < *len)
	// 	printf("\033[0;92m(%d)\033[0m\n", data->list_simu[x]);
	// 	printf("------------------------------------------------\n");
	while (data->list_simu[0] != nb_to_remove)
	{
		rotate_tab(data->list_simu, len);
	}
	rotate_tab(data->list_simu, len);
	// *len = *len - 1;
	data->lenght_list_simu--;
	// x = -1;
	// while (++x < *len)
	// 	printf("\033[0;92m(%d)\033[0m\n", data->list_simu[x]);
	return (data->list_simu);
}

int		find_best_insert(t_data *data, int *list_b, int len_list_b, int b_nb_find_move)
{
	int	i;
	int c;
	int	nbmove;
	int	posnb;
	int	distnb;
	int	minmove;
	int	nb_minmove;
	int	tab[len_list_b];
	int	len_tab;

	// depth++;
	// getchar();
	len_tab = len_list_b;
	data->lenght_list_simu = len_list_b;
	// printf("MONAKS | %d | MONAKS\n", depth);
	i = -1;
	while(++i < len_tab)
	{
		tab[i] = list_b[i];
		data->list_simu[i] = list_b[i];
	}
	// printf("---\n");
	i = 0;
	nb_minmove = 0;
	minmove = data->lenght_list_a + data->lenght_list_b;
	// minmove = -1;
	c = 0;
	// if (depth < 1)
	// {
		// while (i < len_tab - 1)
		// {
			// data->list_simu = ft_get_new_listb(data, tab, &len_tab, tab[i]);
			// printf("\033[93m distnb = %d  : %lu\033[0m\n", distnb, data->lenght_list_simu);
			// distnb = distnb + find_best_insert(data, ft_get_new_listb(data, tab, &len_tab, tab[i]), len_tab, depth + 1);
			// i++;
		// }
	// }
	// getchar();
	while (i < len_tab - 1)
	{
		// printf("segpagmafault tab[i] = %d | %d . %d\n", tab[i], i , list_b[i - 1]);
		// 	printf("\033[0;34m");
		// 	print_list(data);
		// 	printf("\033[0m\n");
		if (b_nb_find_move == 1)
			posnb = ft_find(data, data->find_nb_best_move, 'b');
		else
			posnb = ft_find(data, tab[i], 'b');
		// printf("fault\n");
		// posnb = 1;
		if (posnb > (int)(len_tab / 2))
			distnb = (posnb - len_tab) * -1;
		else
			distnb = posnb;
		while (data->list_a[c] < tab[posnb])
			c++;
		if (c > (int)(data->lenght_list_a / 2))
			c = (c - data->lenght_list_a) * -1;
		distnb = distnb + c;
		// printf("(distnb = %d)(c = %d) tab[posnb] = %d | minmove = %d\n", distnb, c, tab[posnb], minmove);
		// if (minmove == -1);
		// {
		// 	minmove = distnb;
		// 	nb_minmove = tab[posnb];
		// }
		if (distnb < minmove)
		{
			minmove = distnb;
			nb_minmove = tab[posnb];
		}
		// printf("(distnb = %d)(c = %d) tab[posnb] = %d | minmove = %d\n", distnb, c, tab[posnb], minmove);
		i++;
	}
	// getchar();

		// if (depth < 1)
		// {
		// 	data->list_simu = ft_get_new_listb(data, tab, &len_tab, nb_minmove);
		// 	distnb = distnb + find_best_insert(data, data->list_simu, len_tab, depth + 1);
		// 	// printf("\033[93m distnb = %d\033[0m\n", distnb);
		// }
	printf("\033[0;91m DISTNB = %d | c = %d || minmove = %d & nb_minmove = %d  ......   depth == %d\033[0m\n", distnb, c, minmove, nb_minmove, b_nb_find_move);
	// if (len_tab > 4)
	// {
	// 	// getchar();
	// 	*tab = ft_get_new_listb(data, tab, &len_tab, 8);
	// 	// getchar();
	// 	// printf("MUK\n");
	// 	find_best_insert(data, tab, len_tab);
	// }
	// printf("MUK %d\n", minmove);
	data->last_min_move = minmove;
	return (nb_minmove);
}

void	ft_find_next_best(t_data *data)
{
	int	nb;
	int i;
	int	kekw;
	int count;
	int ret;
	int best_move;
	// getchar();
	printf("\033[0;92mdocarrive\n");


	ret = -1;
	i = 0;
	best_move = data->lenght_list_a + data->lenght_list_b;
	while (i < data->lenght_list_b)
	{
		data->find_nb_best_move = data->list_b[i];
		nb = find_best_insert(data, data->list_b, data->lenght_list_b, 1);
		ret = data->last_min_move;
		// data->find_nb_best_move = data->list_b[1];
		data->list_simu = ft_get_new_listb(data, data->list_b, data->lenght_list_simu, data->list_b[i]);
		printf("\033[0;34mMonkas\n");
		getchar();
		printf("...\n");
		int y = -1;
		while (++y < data->lenght_list_simu)
			printf("(%d)", data->list_simu[y]);
		printf("\n...\n");		
		printf("Monkas\033[0m\n");
		kekw = find_best_insert(data, data->list_simu, data->lenght_list_simu, 0);
		ret += data->last_min_move;
		if (ret < best_move)
		{
			best_move = ret;
		}
		ret = data->lenght_list_a + data->lenght_list_b;
		i++;
		printf("\033[0;93m nb = %d | kekw = %d | ret = %d || best_move = %d\033[0m\n", nb, kekw, ret, best_move);
	}



	print_list(data);
	printf("---\n");
	i = -1;
	while (++i < data->lenght_list_simu)
		printf("(%d)\n", data->list_simu[i]);
	printf("---\033[0;91m\n");
	print_list(data);

	printf("\033[0;92mdocleave\033[0m\n");
	getchar();
}

void	big_sort(t_data *data)
{
	int	min;
	int	max;
	int	nb_insert;

	min = data->list_a[find_min(data)];
	max = data->list_a[find_max(data)];
	// printf("\033[0;92m min = %d, max = %d, data->list_a[0] = %d\033[0m\n", min, max, data->list_a[0]); 
	while(data->lenght_list_a > 5)
	{
		if (data->list_a[0] != min && data->list_a[0] != max)
			exec_stack(data, "pb");
		else
			exec_stack(data, "ra");
	}
	small_sort(data, 6);
	// print_list(data);
	// printf("data->list_b[0] = %d\n", data->list_b[0]);
	// exec_stack(data, "rb");
	// exec_stack(data, "rb");
	// while(data->lenght_list_b > 0)
	// {
		ft_find_next_best(data);
		nb_insert = find_best_insert(data, data->list_b, data->lenght_list_b, 0);
		if (data->lenght_list_b > 1)
			set_nb_to_first_b(data, nb_insert, ft_find(data, nb_insert, 'b'), (int)(data->lenght_list_b / 2));
		int i = 0;
		// printf("----------   %d\n", data->list_a[data->lenght_list_a - 1]);
		while(data->list_a[0] < data->list_b[0] || data->list_a[data->lenght_list_a - 1] > data->list_b[0])
		{
			int test = 0;
			test = data->list_a[(int)(data->lenght_list_a /2)];
			if (data->list_b[0] > test)
				exec_stack(data, "rra");
			else
				exec_stack(data, "ra");
		}
		// exec_stack(data, "rra");
		exec_stack(data, "pa");
		int x = find_min(data);
		set_nb_to_first_a(data, data->list_a[x], x, (data->lenght_list_a / 2));
	// }


		printf("\033[0;93m");
		print_list(data);
		printf("\033[0m\n");

}