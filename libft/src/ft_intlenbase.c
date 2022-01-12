/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlenbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:18:17 by ladawi            #+#    #+#             */
/*   Updated: 2022/01/11 14:52:53 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int	ft_intlenbase(long int nb, int base)
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
			i = i * base;
	}
	if (nb < 0)
	{
		while (nb < i + 1 && len++ > 0)
			i *= base;
	}
	if (len == 0)
		len = 1;
	return (len);
}
