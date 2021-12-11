/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:45:17 by ladawi            #+#    #+#             */
/*   Updated: 2021/12/11 21:51:39 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <stdio.h>

typedef struct	s_data
{
	int		*list_a;
	size_t	lenght_list_a;
	int		*list_b;
	size_t	lenght_list_b;
	int		*list_simu;
	size_t	lenght_list_simu;
	int		count;
	size_t	index_max;
	int		mediane;
	int		pivot;
	int		selec_sort_done;
	int		last_min_move;
	int		find_nb_best_move;
}				t_data;

void		print_list(t_data *data);
int			get_list(int ac, char **av, t_data *data);
void		small_sort(t_data *data, int ac);
void		mini_sort(t_data *data);
void		big_sort(t_data *data);
int			find_best_insert(t_data *data, int *tab, int len_tab, int depth);
void		insertion_sort(t_data *data);
int			set_nb_to_first_a(t_data *data, int nb, int pos_nb, int median);
int			set_nb_to_first_b(t_data *data, int nb, int pos_nb, int median);
int			check(int ac, char **av);
int			check_double(t_data *data, int index);
int			get_midiane(t_data *data);
int			get_midiane_n(t_data *data, int start, int end);
void		set_pos_list(t_data *data);
int			ft_find(t_data *data, int nb, char list);
int			find_min(t_data *data);
int			find_max(t_data *data);
int			swap_a(t_data *data);
int			swap_b(t_data *data);
int			swap_ss(t_data *data);
int			rotate_a(t_data *data);
int			rotate_b(t_data *data);
int			rotate_rr(t_data *data);
int			rev_rotate_rr(t_data *data);
int			push_a(t_data *data);
int			push_b(t_data *data);
int			rev_rotate_a(t_data *data);
int			rev_rotate_b(t_data *data);
void		exec_stack(t_data *data, char *str);
void		sort_pars(t_data *data, int ac);
void		selec_sort(t_data *data);
int			is_int(t_data *data, long int nb);
int			get_max(t_data *data);
void		try_quicksort(t_data *data, int start, int end, int depth);


#endif