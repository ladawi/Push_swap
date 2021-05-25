/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:45:17 by ladawi            #+#    #+#             */
/*   Updated: 2021/05/25 16:27:09 by ladawi           ###   ########.fr       */
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
	
}				t_data;

int			get_list(int ac, char **av, t_data *data);
int			check(int ac, char **av);
int			check_double(t_data *data, int index);
int			swap_a(t_data *data);
int			swap_b(t_data *data);
int			swap_ss(t_data *data);
int			rotate_a(t_data *data);
int			rotate_b(t_data *data);
int			rotate_rr(t_data *data);
int			push_a(t_data *data);
int			push_b(t_data *data);
int			rev_rotate_a(t_data *data);
void		quick_sort(t_data *data, int first, int last);



#endif	