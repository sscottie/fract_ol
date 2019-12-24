/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 22:09:14 by sscottie          #+#    #+#             */
/*   Updated: 2019/08/04 17:36:33 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		negative;
	long	res;

	res = 0;
	negative = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' \
			|| *str == '\f' || *str == '\v' || *str == '\r')
		str++;
	if (*str == '-' && str++)
		negative = -1;
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		if ((res * 10 + ((int)*str - 48) - ((int)*str - 48)) / 10 != res)
		{
			if (negative == -1)
				return (0);
			else
				return (-1);
		}
		res = res * 10 + ((int)*str - 48);
		str++;
	}
	return ((int)res * negative);
}
