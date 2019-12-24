/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_oct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:38:41 by sscottie          #+#    #+#             */
/*   Updated: 2019/10/07 21:10:47 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_with_oct(t_all *st, char **s, int len)
{
	int		i;
	char	*temp;
	char	*temp2;

	i = 0;
	if (st->acc != -1 && st->acc > len)
		foo(s, st, &len);
	if (st->flag[2] == '#')
	{
		if ((st->acc <= len || (st->acc == 0 && st->len != 0)) && **s != '0')
		{
			temp = ft_memalloc(ft_strlen(*s) + 1);
			temp[0] = '0';
			temp2 = *s;
			while (temp2[i] != '\0')
			{
				temp[i + 1] = temp2[i];
				i++;
			}
			*s = ft_strdup(temp);
			free(temp);
			free(temp2);
		}
	}
}

void	oct_with_flags(t_all *st, char *s, int len)
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
	else if (st->flag[0] == '0' && st->acc == -1)
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
		do_for_positive(st, s, len);
}

void	do_for_oct(t_all *st)
{
	unsigned int	buf;
	char			*s;
	int				len;

	buf = (unsigned int)va_arg(st->args, unsigned int);
	if (buf == 0 && st->acc != -1 && st->flag[2] != '#')
		null_with_acc(st);
	else
	{
		s = ft_l_itoa_base(buf, 8);
		len = ft_strlen(s);
		if ((st->acc != -1 && st->acc > len) || st->flag[2] == '#')
			fill_with_oct(st, &s, len);
		len = ft_strlen(s);
		if (st->flag[0] != 'e')
		{
			if (st->flag[1] != 'e')
				ft_fwrite(0, &st->flag[1], 1);
		}
		oct_with_flags(st, s, len);
		free(s);
	}
}
