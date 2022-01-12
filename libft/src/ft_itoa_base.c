/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:39:47 by ladawi            #+#    #+#             */
/*   Updated: 2022/01/11 15:03:58 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

char	*ft_itoa_base_2(int n, long long int base, int i, char *nbr)
{
	while (i-- > 0)
	{
		if (n % base > 9)
			nbr[i] = (n % base) + ('a' - 10);
		else
			nbr[i] = (n % base) + ('0'));
		n = n / base;
	}
	return (nbr);
}

char	*ft_itoa_base(int n, long long int base)
{
	long long int	i;
	int				neg;
	char			*nbr;

	i = 1;
	neg = 0;
	if (n < 0)
	{
		if (base == 10)
			neg = 1;
		n = -n;
	}
	while (ft_pow(base, i) - 1 < n)
		i++;
	nbr = (char *)malloc(sizeof(char) * (i + neg + 1));
	if (!(nbr))
		return (0);
	i = i + neg;
	nbr[i + neg] = '\0';
	nbr = ft_itoa_base_2(n, base, i, nbr);
	if (neg)
		nbr[0] = '-';
	return (nbr);
}
