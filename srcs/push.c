/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:10:00 by ladawi            #+#    #+#             */
/*   Updated: 2021/09/14 17:26:39 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void	push_b(t_push_swap *push_swap)
{
	t_chain	*tmp;

	tmp = push_swap->list_a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	add_maillon(push_swap->list_b, tmp->next->nb);
	tmp->next = NULL;
}
