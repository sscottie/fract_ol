/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:30:26 by sscottie          #+#    #+#             */
/*   Updated: 2019/04/24 16:16:22 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*c1;
	char	*c2;

	if (n == 0 || dst == src)
		return (dst);
	c1 = (char *)dst;
	c2 = (char *)src;
	while (--n)
		*c1++ = *c2++;
	*c1 = *c2;
	return (dst);
}
