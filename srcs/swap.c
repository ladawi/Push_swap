/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:00:42 by ladawi            #+#    #+#             */
/*   Updated: 2021/09/13 15:54:08 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void		swap_a(t_push_swap *push_swap)
{
	void	*buff;

	// push_swap->list_a_tail->prev = push_swap->list_a_tail->next;
	// push_swap->list_a_tail->next->next = push_swap->list_a_tail;
	// push_swap->list_a_tail->next->prev = 0;
	// buff = push_swap->list_a_tail->next->next;
	// push_swap->list_a_tail->next = buff;
	push_swap->list_a_tail = set_list_tail(push_swap, push_swap->list_a);
	return ;
}