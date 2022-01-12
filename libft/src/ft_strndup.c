/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 10:08:43 by ladawi            #+#    #+#             */
/*   Updated: 2022/01/11 15:55:37 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s, size_t n)
{
	int		slen;
	char	*ptr;

	slen = ft_strlen(s) + 1;
	ptr = malloc(n + 1);
	if (!(ptr))
		return (NULL);
	ptr[n + 1] = 0;
	ft_memcpy(ptr, s, n);
	return (ptr);
}
