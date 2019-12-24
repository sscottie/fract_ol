/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 01:33:24 by sscottie          #+#    #+#             */
/*   Updated: 2019/09/06 16:57:14 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_size(t_all *st)
{
	if (st->fmt_cp[st->i] == 'l' || st->fmt_cp[st->i] == 'h' || \
		st->fmt_cp[st->i] == 'L')
	{
		if (st->fmt_cp[st->i] == 'l' && st->fmt_cp[st->i + 1] == 'l')
		{
			st->size = 'L';
			st->i += 2;
		}
		else if (st->fmt_cp[st->i] == 'h' && st->fmt_cp[st->i + 1] == 'h')
		{
			st->size = 'H';
			st->i += 2;
		}
		else
			st->size = st->fmt_cp[st->i++];
	}
}

void	fill_len_acc(t_all *st)
{
	while (ft_isdigit(st->fmt_cp[st->i]) == 1 && st->fmt_cp[st->i + 1])
	{
		st->len = st->len * 10 + (st->fmt_cp[st->i] - 48);
		st->i++;
	}
	if (st->fmt_cp[st->i] == '.')
	{
		st->acc = 0;
		while (ft_isdigit(st->fmt_cp[++st->i]) == 1)
			st->acc = st->acc * 10 + (st->fmt[st->i] - 48);
	}
	fill_size(st);
	if (ft_strcmp(&st->fmt_cp[st->i], "cspdiuoxXf\%") == 1)
		st->type = st->fmt_cp[st->i];
}

void	fill_flags(t_all *st)
{
	while (st->fmt_cp[st->i] == '-' || st->fmt_cp[st->i] == '0' || \
			st->fmt_cp[st->i] == '+' || st->fmt_cp[st->i] == ' ' || \
			st->fmt_cp[st->i] == '#')
	{
		if (st->fmt_cp[st->i] == '-' || st->fmt_cp[st->i] == '0')
		{
			if (st->fmt_cp[st->i] == '-')
				st->flag[0] = st->fmt_cp[st->i];
			else if (st->fmt_cp[st->i] == '0' && st->flag[0] != '-')
				st->flag[0] = st->fmt_cp[st->i];
		}
		else if (st->fmt_cp[st->i] == '+' || st->fmt_cp[st->i] == ' ')
		{
			if (st->fmt_cp[st->i] == '+')
				st->flag[1] = st->fmt_cp[st->i];
			else if (st->fmt_cp[st->i] == ' ' && st->flag[1] != '+')
				st->flag[1] = st->fmt_cp[st->i];
		}
		else if (st->fmt_cp[st->i] == '#')
			st->flag[2] = '#';
		++st->i;
	}
	fill_len_acc(st);
}
