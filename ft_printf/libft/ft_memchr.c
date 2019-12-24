/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:14:38 by sscottie          #+#    #+#             */
/*   Updated: 2019/04/24 18:24:40 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*ar;
	int				i;
	unsigned char	c2;

	ar = (unsigned char *)arr;
	i = 0;
	c2 = (unsigned char)c;
	while (i < (int)n)
	{
		if (ar[i] == c2)
			return (ar + i);
		i++;
	}
	return (NULL);
}
