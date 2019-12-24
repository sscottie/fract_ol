/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 19:49:05 by rdonnor           #+#    #+#             */
/*   Updated: 2019/10/07 01:20:04 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	t_all		*st;
	int			len;

	if (!(st = (t_all*)malloc(sizeof(t_all))))
		return (-1);
	st->fmt = (char *)fmt;
	st->fmt_cp = st->fmt;
	st->i = 0;
	len = ft_strlen(st->fmt);
	st = init_st(st);
	if (fmt)
	{
		va_start(st->args, fmt);
		st->len = parse(st);
		va_end(st->args);
	}
	len = st->len;
	free(st);
	return (len);
}
