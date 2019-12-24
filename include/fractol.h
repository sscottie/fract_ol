/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:12:01 by sscottie          #+#    #+#             */
/*   Updated: 2019/11/12 17:12:41 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <OpenCL/opencl.h>
# include <math.h>
# include "var_cl.h"

typedef struct			s_cl
{
	cl_int				ret;
	cl_platform_id		pl;
	cl_device_id		dev;
	cl_context			context;
	cl_program			prog;
	cl_command_queue	cq;
	cl_kernel			kernel;
	cl_mem				buf;
	size_t				gws[1];
	int					buf_len;
	int					iter;
}						t_cl;

typedef struct			s_img
{
	void				*img_ptr;
	int					*data;
	int					size_l;
	int					bpp;
	int					endian;
}						t_img;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win;
	t_img				img;
}						t_mlx;

typedef struct			s_st
{
	t_mlx				*mlx;
	t_cl				*cl;
	t_var				var;
	char				*av;
	int					trigger;
}						t_st;

void					init(char *av);
int						key_hook(int key, void *param);
void					ft_destroy(t_mlx *mlx);
int						ft_close(void *param);
int						iter(int key, int x, int y, void *param);
void					render(t_st *st);
void					var_init(t_st *st);
int						mouse_move(int x, int y, void *param);
void					change_color(int key, t_st *st);

#endif
