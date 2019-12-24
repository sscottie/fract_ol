/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 03:57:34 by sscottie          #+#    #+#             */
/*   Updated: 2019/11/12 17:11:22 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	make_iter(int key, t_st *st)
{
	st->var.max_iter = key == 1 ? st->var.max_iter + 50 : st->var.max_iter - 50;
	st->cl->ret = clSetKernelArg(st->cl->kernel, 1, \
						sizeof(st->var), (void *)&(st->var));
	render(st);
}

static void	move(int key, t_st *st)
{
	double	step;
	int		sign;

	step = (st->var.ymax - st->var.ymin) / 100;
	if (key == 0 || key == 123 || key == 2 || key == 124)
	{
		sign = key == 0 || key == 123 ? 1 : -1;
		st->var.xmax += step * sign;
		st->var.xmin += step * sign;
	}
	else if (key == 1 || key == 125 || key == 13 || key == 126)
	{
		sign = key == 1 || key == 125 ? 1 : -1;
		st->var.ymax += step * sign;
		st->var.ymin += step * sign;
	}
	st->cl->ret = clSetKernelArg(st->cl->kernel, 1, \
					sizeof(st->var), (void *)&(st->var));
	render(st);
}

static void	zoom(int key, int x, int y, t_st *st)
{
	int		sign;
	double	step;

	sign = key == 5 ? 1 : -1;
	step = (st->var.ymax - st->var.ymin) / 100 * 5;
	st->var.xmin = st->var.xmin + (double)x / WIDTH * \
						step * sign * ((double)WIDTH / HEIGHT);
	st->var.xmax = st->var.xmax - (double)(WIDTH - x) / WIDTH * \
							step * sign * ((double)WIDTH / HEIGHT);
	st->var.ymin = st->var.ymin + (double)y / HEIGHT * step * sign;
	st->var.ymax = st->var.ymax - (double)(HEIGHT - y) \
									/ HEIGHT * step * sign;
	st->cl->ret = clSetKernelArg(st->cl->kernel, 1, \
					sizeof(st->var), (void *)&(st->var));
	render(st);
}

int			key_hook(int key, void *param)
{
	t_st *st;

	st = (t_st *)param;
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 0 || key == 1 || key == 2 || key == 13 \
		|| key == 123 || key == 124 || key == 125 || key == 126)
		move(key, st);
	if (key == 49)
	{
		var_init(st);
		st->cl->ret = clSetKernelArg(st->cl->kernel, \
				1, sizeof(st->var), (void *)&(st->var));
		render(st);
	}
	if (key >= 18 && key <= 22)
		change_color(key, st);
	return (0);
}

int			iter(int key, int x, int y, void *param)
{
	t_st *st;

	st = (t_st *)param;
	if (key == 1 || key == 2)
	{
		make_iter(key, st);
	}
	if (key == 4 || key == 5)
	{
		zoom(key, x, y, st);
	}
	if (key == 3)
		st->trigger = st->trigger == 1 ? 0 : 1;
	return (0);
}
