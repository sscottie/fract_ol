/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:50:38 by sscottie          #+#    #+#             */
/*   Updated: 2019/10/08 19:14:46 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_for_point(t_all *st, char *s, int len)
{
	if (st->len != 0 && st->len > len)
		while (st->len-- - len - 2 > 0)
			ft_fwrite(0, " ", 1);
	ft_fwrite(0, "0x", 2);
	ft_fwrite(0, s, len);
}

static char	*do_lowcase(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		s[i] = ft_tolower(s[i]);
		i++;
	}
	return (s);
}

static void	pointer_with_flags(t_all *st, char *s, int len)
{
	if (st->flag[0] == '-')
	{
		ft_fwrite(0, "0x", 2);
		ft_fwrite(0, s, len);
		while (st->len-- - len - 2 > 0)
			ft_fwrite(0, " ", 1);
	}
	else if (st->flag[0] == '0' && st->acc == -1)
	{
		ft_fwrite(0, "0x", 2);
		ft_fwrite(0, s, len);
		while (st->len-- - len > 0)
			ft_fwrite(0, "0", 1);
	}
	else
		do_for_point(st, s, len);
}

void		do_for_pointer(t_all *st)
{
	void	*buf;
	char	*s;
	int		len;

	buf = va_arg(st->args, void *);
	if (buf == 0 || (void*)buf == NULL)
		null_p_with_acc(st);
	else
	{
		s = ft_l_itoa_base((unsigned long)buf, 16);
		s = do_lowcase(s);
		len = ft_strlen(s);
		pointer_with_flags(st, s, len);
		free(s);
	}
}
