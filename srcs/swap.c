/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:00:42 by ladawi            #+#    #+#             */
/*   Updated: 2021/09/14 16:03:40 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void		swap_a(t_push_swap *push_swap)
{
	t_chain		*tmp;

	tmp = push_swap->list_a;
	push_swap->list_a = push_swap->list_a->next;
	tmp->next = push_swap->list_a->next;
	push_swap->list_a->next = tmp;
	return ;
}