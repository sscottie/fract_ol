/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:50:38 by sscottie          #+#    #+#             */
/*   Updated: 2019/10/08 20:17:03 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	insert_flag_2(t_all *st)
{
	if (st->flag[2] == '#')
	{
		if (st->fmt_cp[st->i] == 'x')
			ft_fwrite(0, "0x", 2);
		else
			ft_fwrite(0, "0X", 2);
		st->len -= 2;
	}
}

char	*check_letter(char *s, t_all *st)
{
	int	i;

	i = 0;
	if (st->fmt_cp[st->i] == 'x')
		while (s[i] != '\0')
		{
			s[i] = ft_tolower(s[i]);
			i++;
		}
	else if (st->fmt_cp[st->i] == 'X')
		while (s[i] != '\0')
		{
			s[i] = ft_toupper(s[i]);
			i++;
		}
	return (s);
}

void	hex_with_flags(t_all *st, char *s, int len)
{
	if (st->flag[0] == '-')
	{
		if (st->flag[1] != 'e')
		{
			ft_fwrite(0, &st->flag[1], 1);
			st->len--;
		}
		insert_flag_2(st);
		ft_fwrite(0, s, len);
		while (st->len-- - len > 0)
			ft_fwrite(0, " ", 1);
	}
	else if (st->flag[0] == '0' && st->acc == -1)
	{
		insert_flag_2(st);
		while (st->len-- - len > 0)
			ft_fwrite(0, "0", 1);
		ft_fwrite(0, s, len);
	}
	else
		do_for_positive_hex(st, s, len);
}

void	do_for_hex(t_all *st)
{
	unsigned int	buf;
	char			*s;
	int				len;

	buf = (unsigned int)va_arg(st->args, void *);
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
