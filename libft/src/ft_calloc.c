/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:15:40 by ladawi            #+#    #+#             */
/*   Updated: 2022/01/11 14:39:41 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*ptr;
	int			len;

	len = count * size;
	if (!(len))
		len++;
	ptr = (void *)malloc(len);
	if (!(ptr))
		return (0);
	ft_bzero(ptr, len);
	return (ptr);
}
