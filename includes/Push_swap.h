/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:45:17 by ladawi            #+#    #+#             */
/*   Updated: 2021/12/08 15:05:58 by ladawi           ###   ########.fr       */
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
	int		count;
	size_t	index_max;
	int		mediane;
}				t_data;

int			get_list(int ac, char **av, t_data *data);
int			check(int ac, char **av);
int			check_double(t_data *data, int index);
int			get_midiane(t_data *data);
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
void		sort(t_data *data, int ac);
void		quick_sort(t_data *data, int first, int last);
void		selec_sort(t_data *data);
int			is_int(t_data *data, long int nb);
int			get_max(t_data *data);


#endif	