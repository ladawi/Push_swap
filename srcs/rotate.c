/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:13:51 by ladawi            #+#    #+#             */
/*   Updated: 2021/09/14 16:15:21 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void	rotate_a(t_push_swap *push_swap)
{
	t_chain	*tmp;
	t_chain	*buff;

	tmp = push_swap->list_a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	buff = tmp->next;
	tmp->next = NULL;
	buff->next = push_swap->list_a;
	push_swap->list_a = buff;
	return ;
}