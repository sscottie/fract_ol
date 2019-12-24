/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_sized_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 23:05:27 by sscottie          #+#    #+#             */
/*   Updated: 2019/10/07 11:12:03 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	do_for_l_int(t_all *st)
{
	long		buf;
	char		*s;
	int			len;
	int			minus;

	buf = (long int)va_arg(st->args, long long int);
	if (buf == 0 && st->acc != -1)
		null_with_acc(st);
	else
	{
		minus = (buf < 0) ? 1 : 0;
		s = ft_l_itoa(ft_labs(buf));
		len = ft_strlen(s);
		if (st->acc > len)
			foo(&s, st, &len);
		if (minus == 1)
			do_for_negative(st, s, len);
		else
			int_with_flags(st, s, len);
		free(s);
	}
}

void	do_for_ll_int(t_all *st)
{
	long long	buf;
	char		*s;
	int			len;
	int			minus;

	buf = (long long int)va_arg(st->args, long long int);
	if (buf == 0 && st->acc != -1)
		null_with_acc(st);
	else
	{
		minus = (buf < 0 && buf != LLONG_MIN) ? 1 : 0;
		s = ft_ll_itoa(ft_llabs(buf));
		len = ft_strlen(s);
		if (st->acc > len)
			foo(&s, st, &len);
		if (minus == 1)
			do_for_negative(st, s, len);
		else
			int_with_flags(st, s, len);
		free(s);
	}
}

void	do_for_h_int(t_all *st)
{
	short int	buf;
	char		*s;
	int			len;
	int			minus;

	buf = (short int)va_arg(st->args, int);
	if (buf == 0 && st->acc != -1)
		null_with_acc(st);
	else
	{
		minus = (buf < 0) ? 1 : 0;
		s = ft_itoa(ft_abs((int)buf));
		len = ft_strlen(s);
		if (st->acc > len)
			foo(&s, st, &len);
		if (minus == 1)
			do_for_negative(st, s, len);
		else
			int_with_flags(st, s, len);
		free(s);
	}
}

void	do_for_hh_int(t_all *st)
{
	int			buf;
	char		*s;
	int			len;
	int			minus;

	buf = (signed char)va_arg(st->args, int);
	if (buf == '0' && st->acc != -1)
		null_with_acc(st);
	else
	{
		minus = (buf < 0) ? 1 : 0;
		s = ft_l_itoa(ft_abs(buf));
		len = ft_strlen(s);
		if (st->acc > len)
			foo(&s, st, &len);
		if (minus == 1)
			do_for_negative(st, s, len);
		else
			int_with_flags(st, s, len);
		free(s);
	}
}
