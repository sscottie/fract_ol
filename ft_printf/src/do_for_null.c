/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:52:14 by sscottie          #+#    #+#             */
/*   Updated: 2019/10/08 21:28:02 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	null_no_flags(t_all *st)
{
	while (st->len-- - st->acc > 1)
		ft_fwrite(0, " ", 1);
	if (st->flag[1] == '+')
		ft_fwrite(0, "+", 1);
	else
		ft_fwrite(0, " ", 1);
	while (st->acc-- > 0)
		ft_fwrite(0, "0", 1);
}

static void	pointer_no_flags(t_all *st)
{
	while (st->len-- - st->acc - 2 > 2)
		ft_fwrite(0, " ", 1);
	ft_fwrite(0, "0x0", 3);
	while (st->acc-- > 0)
		ft_fwrite(0, "0", 1);
}

void		null_with_hex(t_all *st)
{
	int i;

	i = 0;
	if (st->len == 0 && st->acc == 0 && st->flag[1] == 'e')
		return ;
	else if (st->len <= st->acc)
	{
		if (st->flag[1] != 'e')
			ft_fwrite(0, &st->flag[1], 1);
		while (st->acc-- > 0)
			ft_fwrite(0, "0", 1);
	}
	else if (st->len > st->acc)
	{
		if (st->flag[0] == '-')
		{
			while (st->acc - i++ > 0)
				ft_fwrite(0, "0", 1);
			while (st->len-- - st->acc > 0)
				ft_fwrite(0, " ", 1);
		}
		else
			null_no_flags(st);
	}
}

void		null_with_acc(t_all *st)
{
	if (st->len == 0 && st->acc == 0 && st->flag[1] == 'e')
		return ;
	else if (st->len <= st->acc)
	{
		if (st->flag[1] != 'e')
			ft_fwrite(0, &st->flag[1], 1);
		while (st->acc-- > 0)
			ft_fwrite(0, "0", 1);
	}
	else if (st->len > st->acc)
	{
		if (st->flag[0] == '-')
			put_null(st);
		else
			null_no_flags(st);
	}
}

void		null_p_with_acc(t_all *st)
{
	int i;

	i = 0;
	if (st->len == 0 && st->acc == 0 && st->flag[1] == 'e')
		ft_fwrite(0, "0x0", 3);
	else if (st->len <= st->acc)
	{
		ft_fwrite(0, "0x0", 3);
		while (st->acc-- > 0)
			ft_fwrite(0, "0", 1);
	}
	else if (st->len > st->acc)
	{
		if (st->flag[0] == '-')
		{
			ft_fwrite(0, "0x0", 3);
			while (st->acc - i++ > 0)
				ft_fwrite(0, "0", 1);
			while (st->len-- - st->acc > 0)
				ft_fwrite(0, " ", 1);
		}
		else
			pointer_no_flags(st);
	}
}
