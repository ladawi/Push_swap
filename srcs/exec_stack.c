/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:43:32 by ladawi            #+#    #+#             */
/*   Updated: 2021/12/17 22:43:37 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void	exec_stack(t_data *data, char *str)
{
	if (ft_strncmp("ra", str, ft_strlen(str)) == 0)
		rotate_a(data);
	if (ft_strncmp("rb", str, ft_strlen(str)) == 0)
		rotate_b(data);
	if (ft_strncmp("pa", str, ft_strlen(str)) == 0)
		push_a(data);
	if (ft_strncmp("pb", str, ft_strlen(str)) == 0)
		push_b(data);
	if (ft_strncmp("sa", str, ft_strlen(str)) == 0)
		swap_a(data);
	if (ft_strncmp("sb", str, ft_strlen(str)) == 0)
		swap_b(data);
	if (ft_strncmp("ss", str, ft_strlen(str)) == 0)
		swap_ss(data);
	if (ft_strncmp("rr", str, ft_strlen(str)) == 0)
		rotate_rr(data);
	if (ft_strncmp("rrr", str, ft_strlen(str)) == 0)
		rev_rotate_rr(data);
	if (ft_strncmp("rra", str, ft_strlen(str)) == 0)
		rev_rotate_a(data);
	if (ft_strncmp("rrb", str, ft_strlen(str)) == 0)
		rev_rotate_b(data);
	ft_putendl_fd(str, 1);
	data->count++;
}
