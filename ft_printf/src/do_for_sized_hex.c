/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_sized_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 02:15:21 by sscottie          #+#    #+#             */
/*   Updated: 2019/10/07 06:59:15 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_for_positive_hex(t_all *st, char *s, int len)
{
	st->len = st->flag[2] == '#' ? st->len -= 2 : st->len;
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
	insert_flag_2(st);
	ft_fwrite(0, s, len);
}

void	do_for_l_hex(t_all *st)
{
	unsigned long	buf;
	char			*s;
	int				len;

	buf = (unsigned long)va_arg(st->args, unsigned long);
	if (buf == 0 && st->acc != -1)
		null_with_hex(st);
	else if (buf == 0 && st->acc == -1)
		null_with_no_acc_hex(st);
	else
	{
		s = ft_l_itoa_base(buf, 16);
		len = ft_strlen(s);
		if (st->acc != -1 && st->acc > len)
			foo(&s, st, &len);
		s = check_letter(s, st);
		len = ft_strlen(s);
		if (st->flag[0] != 'e')
		{
			if (st->flag[1] != 'e')
				ft_fwrite(0, &st->flag[1], 1);
		}
		hex_with_flags(st, s, len);
		free(s);
	}
}

void	do_for_ll_hex(t_all *st)
{
	unsigned long long	buf;
	char				*s;
	int					len;

	buf = (unsigned long long)va_arg(st->args, unsigned long long);
	if (buf == 0 && st->acc != -1)
		null_with_hex(st);
	else if (buf == 0 && st->acc == -1)
		null_with_no_acc_hex(st);
	else
	{
		s = ft_ll_itoa_base(buf, 16);
		len = ft_strlen(s);
		if (st->acc != -1 && st->acc > len)
			foo(&s, st, &len);
		s = check_letter(s, st);
		len = ft_strlen(s);
		if (st->flag[0] != 'e')
		{
			if (st->flag[1] != 'e')
				ft_fwrite(0, &st->flag[1], 1);
		}
		hex_with_flags(st, s, len);
		free(s);
	}
}

void	do_for_h_hex(t_all *st)
{
	unsigned short int	buf;
	char				*s;
	int					len;

	buf = (unsigned short int)va_arg(st->args, unsigned int);
	if (buf == 0 && st->acc != -1)
		null_with_hex(st);
	else if (buf == 0 && st->acc == -1)
		null_with_no_acc_hex(st);
	else
	{
		s = ft_ll_itoa_base(buf, 16);
		len = ft_strlen(s);
		if (st->acc != -1 && st->acc > len)
			foo(&s, st, &len);
		s = check_letter(s, st);
		len = ft_strlen(s);
		if (st->flag[0] != 'e')
		{
			if (st->flag[1] != 'e')
				ft_fwrite(0, &st->flag[1], 1);
		}
		hex_with_flags(st, s, len);
		free(s);
	}
}

void	do_for_hh_hex(t_all *st)
{
	unsigned int	buf;
	char			*s;
	int				len;

	buf = (unsigned char)va_arg(st->args, unsigned int);
	if (buf == 0 && st->acc != -1)
		null_with_hex(st);
	else if (buf == 0 && st->acc == -1)
		null_with_no_acc_hex(st);
	else
	{
		s = ft_ll_itoa_base(buf, 16);
		len = ft_strlen(s);
		if (st->acc != -1 && st->acc > len)
			foo(&s, st, &len);
		s = check_letter(s, st);
		len = ft_strlen(s);
		if (st->flag[0] != 'e')
		{
			if (st->flag[1] != 'e')
				ft_fwrite(0, &st->flag[1], 1);
		}
		hex_with_flags(st, s, len);
		free(s);
	}
}
