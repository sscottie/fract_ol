/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 04:09:43 by sscottie          #+#    #+#             */
/*   Updated: 2019/11/12 17:14:47 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_st *st)
{
	size_t global_work_size[1];

	global_work_size[0] = WIDTH * HEIGHT;
	st->cl->ret = clSetKernelArg(st->cl->kernel, 1, \
						sizeof(st->var), (void *)&(st->var));
	st->cl->ret = clEnqueueNDRangeKernel(st->cl->cq, \
	st->cl->kernel, 1, NULL, global_work_size, NULL, 0, NULL, NULL);
	st->cl->ret = clEnqueueReadBuffer(st->cl->cq, st->cl->buf, \
	CL_TRUE, 0, st->cl->buf_len * sizeof(cl_int), \
		st->mlx->img.data, 0, NULL, NULL);
	mlx_put_image_to_window(st->mlx->mlx_ptr, st->mlx->win, \
			st->mlx->img.img_ptr, 0, 0);
	clFlush(st->cl->cq);
	clFinish(st->cl->cq);
}

int		mouse_move(int x, int y, void *param)
{
	t_st *st;

	st = (t_st *)param;
	if (st->trigger == 1)
	{
		st->var.cx = 4 * ((double)x / WIDTH - 0.5);
		st->var.cy = 4 * ((double)(HEIGHT - y) / HEIGHT - 0.5);
		st->cl->ret = clSetKernelArg(st->cl->kernel, \
				1, sizeof(st->var), (void *)&(st->var));
		render(st);
	}
	return (0);
}

void	change_color(int key, t_st *st)
{
	if (key == 18)
		st->var.color = 2;
	else if (key == 19)
		st->var.color = 4;
	else if (key == 20)
		st->var.color = 8;
	else if (key == 21)
		st->var.color = 16;
	else if (key == 22)
		st->var.color = 32;
	render(st);
}
