#include "var_cl.h"

double map(double current, double end, double new_start, double new_end) {
    return (current / end * (new_end - new_start) + new_start);
}

double	ft_abs(double res)
{
	return (res < 0 ? -res : res);
}

__kernel void	Mandelbrot(__global int* out, t_var var)
{
	int i = get_global_id(0) / WIDTH;
	int j = get_global_id(0) % WIDTH;
	double x_z = map(j, WIDTH, var.xmin, var.xmax);
	double y_z = map(i, HEIGHT, var.ymin, var.ymax);
	double x = x_z;
	double y = y_z;
	int iter = 0;
	double xx = 0;
	double yy = 0;
	double twoXY;
	while (xx + yy <= 4 && iter < var.max_iter)
	{
		xx = x * x;
		yy = y * y;
		twoXY = 2 * x * y;
		x = xx - yy + x_z;
		y = twoXY + y_z;
		iter++;
	}
	if (iter == var.max_iter)
		out[i * WIDTH + j] = 0;
	else
		out[i * WIDTH + j] = iter % 256 << 1 + iter % var.color << 3;
}

__kernel void	Julia(__global int* out, t_var var)
{
	int i = get_global_id(0) / WIDTH;
	int j = get_global_id(0) % WIDTH;
	double x_z = map(j, WIDTH, var.xmin, var.xmax);
	double y_z = map(i, HEIGHT, var.ymin, var.ymax);
	int iter = 0;
	double xtemp = 0;
	while (x_z * x_z + y_z * y_z <= 4 && iter < var.max_iter)
	{
		xtemp = x_z * x_z - y_z * y_z;
		y_z =  2 * x_z * y_z + var.cy;
		x_z = xtemp + var.cx;
		iter = iter + 1;
	}
	if (iter == var.max_iter)
		out[i * 1920 + j] = 0;
	else
		out[i * 1920 + j] = iter % 256 << 17 + iter % var.color << 3;
}

__kernel void	BurningShip(__global int* out, t_var var)
{
	int i = get_global_id(0) / WIDTH;
	int j = get_global_id(0) % WIDTH;
	double x_z = map(j, WIDTH, var.xmin, var.xmax);
	double y_z = map(i, HEIGHT, var.ymin, var.ymax);
	double x = x_z;
	double y = y_z;
	int iter = 0;
	double xx = 0;
	double yy = 0;
	double twoXY;
	while (xx + yy < 4 && iter < var.max_iter)
	{
		xx = x * x;
		yy = y * y;
		twoXY = 2 * x * y;
		x = xx - yy + x_z;
		if (twoXY < 0)
			twoXY = -twoXY;
		y = twoXY + y_z;
		iter++;
	}
	if (iter == var.max_iter)
		out[i * 1920 + j] = 0;
	else
		out[i * 1920 + j] = iter % 128 << 5 + iter % var.color << 3;
}

__kernel void	Uterus(__global int* out, t_var var)
{
	int i = get_global_id(0) / WIDTH;
	int j = get_global_id(0) % WIDTH;
	double x_z = map(j, WIDTH, var.xmin, var.xmax);
	double y_z = map(i, HEIGHT, var.ymin, var.ymax);
	double x = x_z;
	double y = y_z;
	int iter = 0;
	double xx = 0;
	double yy = 0;
	while (xx + yy < 4 && iter < var.max_iter)
	{
		xx = x * x;
		yy = y * y;
		x = (xx - (yy * 3.0) * ft_abs(x)) + x_z;
		y = ((xx * 3.0) - yy) * ft_abs(y) + y_z;
		iter++;
	}
	if (iter == var.max_iter)
		out[i * 1920 + j] = 0;
	else
		out[i * 1920 + j] = iter % 128 << 5 + iter % var.color << 3;
}

__kernel void	Quasi_heart(__global int* out, t_var var)
{
	int i = get_global_id(0) / WIDTH;
	int j = get_global_id(0) % WIDTH;
	double x_z = map(j, WIDTH, var.xmin, var.xmax);
	double y_z = map(i, HEIGHT, var.ymin, var.ymax);
	double x = x_z;
	double y = y_z;
	int iter = 0;
	double xx = 0;
	double yy = 0;
	while (xx + yy < 4 && iter < var.max_iter)
	{
		xx = x * x;
		yy = y * y;
		x = (xx - (yy * 3.0) * ft_abs(x)) + x_z;
		y = ft_abs((xx * 3.0) - yy) * y + y_z;
		iter++;
	}
	if (iter == var.max_iter)
		out[i * 1920 + j] = 0;
	else
		out[i * 1920 + j] = iter % 128 << 5 + iter % var.color << 3;
}

__kernel void	Vertical(__global int* out, t_var var)
{
	int i = get_global_id(0) / WIDTH;
	int j = get_global_id(0) % WIDTH;
	double x_z = map(j, WIDTH, var.xmin, var.xmax);
	double y_z = map(i, HEIGHT, var.ymin, var.ymax);
	double x = x_z;
	double y = y_z;
	int iter = 0;
	double xx = 0;
	double yy = 0;
	double xx2 = 0;
	double yy2 = 0;
	double xxyy = 0;
	while (xx + yy < 4 && iter < var.max_iter)
	{
		xx = x * x;
		yy = y * y;
		yy2 = yy * yy;
		xx2 = xx * xx;
		xxyy = xx * yy;
		x = x * (xx2 - 10 * xxyy + 5 * yy2) + x_z;
		y = -y * (5 * xx2 - 10 * xxyy + yy2) + y_z;
		iter++;
	}
	if (iter == var.max_iter)
		out[i * 1920 + j] = 0;
	else
		out[i * 1920 + j] = iter % 128 << 5 + iter % var.color << 3;
}
