/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:13:51 by ladawi            #+#    #+#             */
/*   Updated: 2021/09/13 15:33:56 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void	rotate_a(t_push_swap *push_swap)
{
	void	*buff;

	push_swap->list_a->next = push_swap->list_a_tail;
	push_swap->list_a->prev->next = NULL;
	push_swap->list_a_tail->prev = push_swap->list_a;
	buff = push_swap->list_a->prev;
	push_swap->list_a->prev = NULL;
	push_swap->list_a = buff;
	push_swap->list_a_tail = set_list_tail(push_swap, push_swap->list_a);
	return ;
}