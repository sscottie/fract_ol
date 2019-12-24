/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 21:17:12 by sscottie          #+#    #+#             */
/*   Updated: 2019/08/04 18:21:50 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *stack, const char *needle)
{
	unsigned int	i;
	unsigned int	k;
	const char		*str;

	str = stack;
	if (!*needle)
		return ((char*)str);
	i = 0;
	while (stack[i] != '\0')
	{
		if (stack[i] == needle[0])
		{
			k = 1;
			while (needle[k] != '\0' && stack[i + k] == needle[k])
				k++;
			if (needle[k] == '\0')
				return ((char*)&str[i]);
		}
		i++;
	}
	return (0);
}
