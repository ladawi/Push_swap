/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:59:04 by ladawi            #+#    #+#             */
/*   Updated: 2021/09/13 15:37:12 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void	rev_rotate_a(t_push_swap *push_swap)
{
	push_swap->list_a->next = push_swap->list_a_tail;
	push_swap->list_a_tail->prev = push_swap->list_a;
	push_swap->list_a_tail->next->prev = NULL;
	push_swap->list_a_tail->next = NULL;
	push_swap->list_a = push_swap->list_a_tail;
	push_swap->list_a_tail = set_list_tail(push_swap, push_swap->list_a);
	return ;
}