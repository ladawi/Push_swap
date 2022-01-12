/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:18:17 by ladawi            #+#    #+#             */
/*   Updated: 2022/01/11 14:49:52 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int	ft_intlen(long int nb)
{
	int				len;
	long int		i;

	if (nb >= 0)
		i = 1;
	else
		i = -1;
	len = 0;
	if (nb >= 0)
	{
		while (nb > i - 1 && len++ > 0)
		{
			i *= 10;
		}
	}
	if (nb < 0)
	{
		while (nb < i + 1 && len++ > 0)
		{
			i *= 10;
		}
	}
	if (len == 0)
		len = 1;
	return (len);
}
