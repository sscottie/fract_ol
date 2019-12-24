/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 19:52:42 by rdonnor           #+#    #+#             */
/*   Updated: 2019/10/08 21:03:22 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			g_buf[SIZE];
static size_t		g_pos;
size_t				g_i;

int	ft_fwrite_c(const char flag, const char *input, size_t len)
{
	int	count;

	if (flag == 0)
	{
		g_i = 0;
		if (*input == '\0')
		{
			g_buf[g_pos++] = input[g_i];
			return (0);
		}
		while (*input && g_i < len)
			g_buf[g_pos++] = input[g_i++];
	}
	else
	{
		count = ft_strlen(g_buf);
		write(1, g_buf, g_pos);
		ft_bzero(g_buf, g_pos);
		g_pos = 0;
		return (count);
	}
	return (0);
}

int	ft_fwrite(const char flag, const char *input, size_t len)
{
	int count;

	if (flag == 0)
	{
		g_i = 0;
		while (*input && g_i < len)
		{
			g_buf[g_pos++] = input[g_i++];
			if (g_pos == SIZE)
			{
				write(1, g_buf, g_pos);
				g_pos = 0;
			}
		}
	}
	else
	{
		count = g_pos;
		write(1, g_buf, g_pos);
		ft_bzero(g_buf, g_pos);
		g_pos = 0;
		return (count);
	}
	return (0);
}
