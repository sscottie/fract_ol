/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 22:25:46 by sscottie          #+#    #+#             */
/*   Updated: 2019/10/02 19:48:13 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_for_percent(t_all *st)
{
	char	c;

	c = '%';
	if (st->flag[0] == '-')
	{
		ft_fwrite(0, &c, 1);
		while (st->len-- > 1)
			ft_fwrite(0, " ", 1);
	}
	else if (st->flag[0] == '0')
	{
		while (st->len-- > 1)
			ft_fwrite(0, "0", 1);
		ft_fwrite(0, &c, 1);
		st->len--;
	}
	else
	{
		while (st->len-- > 1)
			ft_fwrite(0, " ", 1);
		ft_fwrite(0, &c, 1);
		st->len--;
	}
}

void	do_for_char(t_all *st)
{
	char	c;

	c = (char)va_arg(st->args, unsigned int);
	if (st->flag[0] == '-')
	{
		ft_fwrite_c(0, &c, 1);
		while (st->len-- > 1)
			ft_fwrite(0, " ", 1);
	}
	else if (st->flag[0] == '0')
	{
		while (st->len-- > 1)
			ft_fwrite(0, "0", 1);
		ft_fwrite_c(0, &c, 1);
		st->len--;
	}
	else
	{
		while (st->len-- > 1)
			ft_fwrite(0, " ", 1);
		ft_fwrite_c(0, &c, 1);
		st->len--;
	}
}
