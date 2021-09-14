/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:59:04 by ladawi            #+#    #+#             */
/*   Updated: 2021/09/14 16:17:38 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void	rev_rotate_a(t_push_swap *push_swap)
{
	t_chain	*tmp;
	t_chain	*buff;

	buff = push_swap->list_a->next;
	tmp = push_swap->list_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = push_swap->list_a;
	push_swap->list_a->next = NULL;
	push_swap->list_a = buff;
	return ;
}