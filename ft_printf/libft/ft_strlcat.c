/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 19:46:05 by sscottie          #+#    #+#             */
/*   Updated: 2019/04/24 20:00:41 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;

	i = 0;
	while (dst[i] && i < size)
		i++;
	k = i;
	while (src[i - k] && i + 1 < size)
	{
		dst[i] = src[i - k];
		i++;
	}
	if (k < size)
		dst[i] = '\0';
	return (k + ft_strlen(src));
}
