/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:04:26 by ladawi            #+#    #+#             */
/*   Updated: 2021/09/14 17:26:29 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

t_chain		*get_last(t_chain *node)
{
	if (node->next == NULL)
		return (node);
	return (get_last(node->next));
}

t_chain 	*add_maillon(t_chain *head, int nb)
{
	t_chain *new;
	
	if (head->next == NULL)
	{
		new = ft_calloc(sizeof(t_chain), 1);
		new->nb = nb;
		new->next = 0;
		head->next = new;
	}
	else
		add_maillon(head->next, nb);
	return (new);
}

int			is_int(long int nb)
{
	int		i;

	i = 0;
	if (nb > 2147483647 || nb < -2147483647)
		return (-1);
	return (0);
}

int		get_list(t_push_swap *push_swap, int len, char **av)
{
	int	i;
	int	x;
	int	nb;

	i = 0;
	x = 0;
	nb = ft_atoi(av[i + 1]);
	if ((is_int(nb)))
		return (-1);
 	push_swap->list_a->nb = nb;
 	push_swap->list_a->next = 0;
	push_swap->tab_nb[i] = nb;
	while (++i < len)
	{
		nb = ft_atoi(av[i + 1]);
		if ((is_int(nb)))
			return (-1);
 		add_maillon(push_swap->list_a, nb);
		push_swap->tab_nb[i] = nb;
	}
	return(0);
}

void	mini_sort(int *tab, int len)
{
	int		i;
	int		buff;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			buff = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = buff;
			i = 0;
		}
		else
			i++;
	}
}
int		get_median(t_push_swap *push_swap)
{
	mini_sort(push_swap->tab_nb, push_swap->len);
	push_swap->median = push_swap->tab_nb[(int)(push_swap->len / 2)];
	return (0);
}
