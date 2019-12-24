/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:49:10 by sscottie          #+#    #+#             */
/*   Updated: 2019/10/07 09:00:43 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string_with_flags(t_all *st, char *s, int len)
{
	if (st->flag[0] == '-')
	{
		ft_fwrite(0, s, len);
		while (st->len-- - len > 0)
			ft_fwrite(0, " ", 1);
	}
	else if (st->flag[0] == '0')
	{
		while (st->len-- - len > 0)
			ft_fwrite(0, "0", 1);
		ft_fwrite(0, s, len);
	}
	else
	{
		while (st->len-- - len > 0)
			ft_fwrite(0, " ", 1);
		ft_fwrite(0, s, len);
	}
}

void	do_for_string(t_all *st)
{
	int		len;
	char	*s;
	char	*buf;

	s = NULL;
	buf = va_arg(st->args, char *);
	if (!buf)
		buf = "(null)";
	if (st->acc < (int)ft_strlen(buf) && st->acc != -1)
	{
		s = ft_strnew(st->acc);
		s = ft_strncpy(s, buf, st->acc);
	}
	else
		s = buf;
	len = ft_strlen(s);
	if ((st->len == 0 || st->len <= len) && st->flag[0] == 'e')
		ft_fwrite(0, s, len);
	else
		string_with_flags(st, s, len);
	if (st->acc < (int)ft_strlen(buf) && st->acc != -1)
		free(s);
}
