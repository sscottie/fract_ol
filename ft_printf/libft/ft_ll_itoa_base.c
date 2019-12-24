/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_itoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:40:43 by sscottie          #+#    #+#             */
/*   Updated: 2019/10/08 20:03:46 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			find_size(long long tmp, int base)
{
	int size;

	size = 0;
	while (tmp /= base)
		size++;
	return (size);
}

char				*ft_ll_itoa_base(long long value, int base)
{
	char		*str;
	int			size;
	char		*tab;
	int			flag;
	long long	tmp;

	tab = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	flag = (value < 0 && base == 10) ? 1 : 0;
	tmp = value;
	size = find_size(tmp, base);
	size = size + flag + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	str[0] = (flag == 1) ? '-' : '\0';
	while (size > flag)
	{
		str[size - 1] = tab[ft_llabs(value % base)];
		size--;
		value /= base;
	}
	return (str);
}
