/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:31:57 by ladawi            #+#    #+#             */
/*   Updated: 2022/01/11 15:07:06 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!(new_list))
		return (NULL);
	new_list->content = f(lst->content);
	if (!(new_list->content))
	{
		ft_lstclear(&new_list, del);
		return (NULL);
	}
	if (lst->next)
		new_list->next = ft_lstmap(lst->next, f, del);
	else
		new_list->next = NULL;
	return (new_list);
}
