/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 01:12:10 by sscottie          #+#    #+#             */
/*   Updated: 2019/12/24 12:46:48 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	first_render(t_st *st, char *res, char *av)
{
	size_t global_work_size[1];

	global_work_size[0] = WIDTH * HEIGHT;
	st->cl->iter = 0;
	st->cl->ret = clGetPlatformIDs(1, &st->cl->pl, NULL);
	st->cl->ret = clGetDeviceIDs(st->cl->pl, CL_DEVICE_TYPE_GPU, \
			1, &st->cl->dev, NULL);
	st->cl->context = clCreateContext(NULL, 1, &st->cl->dev, NULL, \
													NULL, &st->cl->ret);
	st->cl->cq = clCreateCommandQueue(st->cl->context, st->cl->dev, \
														0, &st->cl->ret);
	st->cl->prog = clCreateProgramWithSource(st->cl->context, 1, \
									(const char **)&(res), NULL, &st->cl->ret);
	st->cl->ret = clBuildProgram(st->cl->prog, 1, \
									&(st->cl->dev), "-I./include", NULL, NULL);
	st->cl->kernel = clCreateKernel(st->cl->prog, av, &st->cl->ret);
	st->cl->buf_len = WIDTH * HEIGHT;
	st->cl->buf = clCreateBuffer(st->cl->context, CL_MEM_READ_WRITE, \
						st->cl->buf_len * sizeof(cl_int), NULL, &st->cl->ret);
	st->cl->ret = clSetKernelArg(st->cl->kernel, 0, sizeof(cl_mem), \
													(void *)&(st->cl->buf));
	st->cl->ret = clSetKernelArg(st->cl->kernel, 1, sizeof(t_var), \
															(void *)&(st->var));
	render(st);
}

static char	*get_kernel(void)
{
	int		fd;
	char	buf[5000];
	int		ret;
	char	*res;

	fd = open("./src/open.cl", \
															O_RDONLY);
	ret = read(fd, buf, 5000);
	res = ft_strnew(ret);
	res = ft_strncpy(res, buf, ret);
	close(fd);
	return (res);
}

static void	init_mlx(t_st *st, char *av)
{
	st->mlx->mlx_ptr = mlx_init();
	st->mlx->win = mlx_new_window(st->mlx->mlx_ptr, WIDTH, HEIGHT, av);
	st->mlx->img.img_ptr = mlx_new_image(st->mlx->mlx_ptr, WIDTH, HEIGHT);
	st->mlx->img.data = (int *)mlx_get_data_addr(st->mlx->img.img_ptr, \
		&(st->mlx->img.bpp), &(st->mlx->img.size_l), &(st->mlx->img.endian));
}

void		var_init(t_st *st)
{
	if (ft_strcmp(st->av, "Julia") == 0)
	{
		st->var.xmax = 1.75;
		st->var.xmin = -1.75;
		st->var.ymin = -1;
		st->var.ymax = (st->var.ymin + \
			(st->var.xmax - st->var.xmin) * HEIGHT / WIDTH);
		st->var.max_iter = 64;
		st->var.cx = -0.4;
		st->var.cy = 0.6;
		st->trigger = 1;
		st->var.color = 2;
	}
	else
	{
		st->var.xmax = 1.0;
		st->var.xmin = -2.5;
		st->var.ymin = -1;
		st->var.ymax = (st->var.ymin + \
			(st->var.xmax - st->var.xmin) * HEIGHT / WIDTH);
		st->var.max_iter = 256;
		st->trigger = 1;
		st->var.color = 2;
	}
}

void		init(char *av)
{
	t_st	*st;
	char	*res;

	if (!(st = (t_st *)malloc(sizeof(t_st))))
		exit(EXIT_FAILURE);
	if (!(st->mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		exit(EXIT_FAILURE);
	if (!(st->cl = (t_cl *)malloc(sizeof(t_cl))))
		exit(EXIT_FAILURE);
	init_mlx(st, av);
	st->av = av;
	res = get_kernel();
	var_init(st);
	first_render(st, res, av);
	mlx_hook(st->mlx->win, 2, 0, key_hook, st);
	mlx_hook(st->mlx->win, 17, 0, ft_close, st);
	mlx_hook(st->mlx->win, 4, 0, iter, st);
	if (*st->av == 'J')
		mlx_hook(st->mlx->win, 6, 0, mouse_move, st);
	mlx_loop(st->mlx->mlx_ptr);
}
