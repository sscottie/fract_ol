/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 12:40:34 by sscottie          #+#    #+#             */
/*   Updated: 2019/09/06 00:14:48 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_intlen(long nbr)
{
	long len;

	len = 0;
	len = (nbr <= 0 ? 1 : 0);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char				*ft_ll_itoa(long long n)
{
	unsigned long long	nbr;
	int					sign;
	long				len;
	char				*alpha;

	sign = (n < 0 ? 1 : 0);
	alpha = NULL;
	len = ft_intlen(n);
	nbr = (n < 0 ? -n : n);
	if (!(alpha = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	alpha[len--] = '\0';
	while (len >= 0)
	{
		alpha[len] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	if (sign == 1)
		alpha[0] = '-';
	return (alpha);
}
