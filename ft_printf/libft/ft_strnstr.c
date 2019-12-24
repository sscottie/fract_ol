/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 21:40:18 by sscottie          #+#    #+#             */
/*   Updated: 2019/08/04 18:22:29 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *stack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	if (needle[0] == '\0')
		return ((char *)stack);
	i = 0;
	while (i < len && stack[i] != '\0')
	{
		k = 0;
		while (needle[k] != '\0')
		{
			if (i + k >= len || stack[i + k] != needle[k])
				break ;
			k++;
		}
		if (needle[k] == '\0')
			return ((char *)(stack + i));
		i++;
	}
	return (0);
}
