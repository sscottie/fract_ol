/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_floats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 00:07:42 by sscottie          #+#    #+#             */
/*   Updated: 2019/10/08 21:47:50 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_for_fpositive(t_all *st, char *s, int len)
{
	if (st->len != 0 && st->len > len && st->flag[1] == 'e')
		while (st->len-- - len > 0)
		{
			ft_fwrite(0, " ", 1);
			st->count++;
		}
	else if (st->len != 0 && st->len > len && st->flag[1] != 'e')
		while (st->len-- - len > 1)
		{
			ft_fwrite(0, " ", 1);
			st->count++;
		}
	if (st->flag[1] != 'e')
	{
		ft_fwrite(0, &st->flag[1], 1);
		st->count++;
	}
	ft_fwrite(0, s, len);
	st += len;
}

static void	do_for_fnegative(t_all *st, char *s, int len)
{
	if (st->flag[0] == '-')
	{
		ft_fwrite(0, "-", 1);
		ft_fwrite(0, s, len);
		while (--st->len - len > 0)
			ft_fwrite(0, " ", 1);
	}
	else if (st->flag[0] == '0')
	{
		ft_fwrite(0, "-", 1);
		while (--st->len - len > 0)
			ft_fwrite(0, "0", 1);
		ft_fwrite(0, s, len);
	}
	else
	{
		while (st->len-- - len > 1)
			ft_fwrite(0, " ", 1);
		ft_fwrite(0, "-", 1);
		ft_fwrite(0, s, len);
	}
}

static void	float_with_flags(t_all *st, char *s, int len)
{
	if (st->flag[0] == '-')
	{
		if (st->flag[1] != 'e')
		{
			ft_fwrite(0, &st->flag[1], 1);
			st->len--;
		}
		ft_fwrite(0, s, len);
		while (st->len-- - len > 0)
			ft_fwrite(0, " ", 1);
	}
	else if (st->flag[0] == '0')
	{
		if (st->flag[1] != 'e')
		{
			ft_fwrite(0, &st->flag[1], 1);
			st->len--;
		}
		while (st->len-- - len > 0)
			ft_fwrite(0, "0", 1);
		ft_fwrite(0, s, len);
	}
	else
		do_for_fpositive(st, s, len);
}

void		do_for_floats(t_all *st)
{
	double		buf;
	char		*s;
	int			len;
	char		*s_buf;
	int			minus;

	buf = (double)va_arg(st->args, double);
	minus = (buf < 0) ? 1 : 0;
	s = ft_convert_float(st, ft_fabs(buf));
	if (st->acc == 0 && st->flag[2] == '#')
		s[ft_strlen(s)] = '.';
	len = ft_strlen(s);
	if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
	{
		s = ft_strcat(ft_memset(s_buf, '0', st->acc - len), s);
		len = ft_strlen(s);
		free(s_buf);
	}
	if (minus == 1)
		do_for_fnegative(st, s, len);
	else
		float_with_flags(st, s, len);
	free(s);
}

void		do_for_l_floats(t_all *st)
{
	long double	buf;
	char		*s;
	int			len;
	char		*s_buf;
	int			minus;

	buf = (long double)va_arg(st->args, long double);
	minus = (buf < 0) ? 1 : 0;
	s = ft_convert_float(st, ft_fabsl(buf));
	if (st->acc == 0 && st->flag[2] == '#')
		s[ft_strlen(s)] = '.';
	len = ft_strlen(s);
	if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
	{
		s = ft_strcat(ft_memset(s_buf, '0', st->acc - len), s);
		len = ft_strlen(s);
		free(s_buf);
	}
	if (minus == 1)
		do_for_fnegative(st, s, len);
	else
		float_with_flags(st, s, len);
	free(s);
}
