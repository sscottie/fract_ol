/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 00:29:43 by sscottie          #+#    #+#             */
/*   Updated: 2019/11/19 00:15:13 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_close(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}

void	check_intra(int ac, char **av)
{
	if (ac == 1)
	{
		ft_printf(GREEN("Choose your destiny, like: ./fractol [TYPE] \
		\n[Mandelbrot] [Julia] [BurningShip] [Uterus] [Quasi_heart] \
[Vertical]\n"));
		exit(EXIT_FAILURE);
	}
	else if ((ft_strcmp(av[1], "Mandelbrot") == 0) || (ft_strcmp(av[1], \
			"Julia") == 0) || (ft_strcmp(av[1], "BurningShip") == 0) || \
			(ft_strcmp(av[1], "Uterus") == 0) || (ft_strcmp(av[1], \
			"Quasi_heart") == 0) || (ft_strcmp(av[1], "Vertical") == 0))
		return ;
	else
	{
		ft_printf(RED("Seems that you've written wrong name of fractal...\
			\nProgram is sensitive to register! Check your argument.\n"));
		ft_printf(GREEN("Choose your destiny, like: ./fractol [TYPE] \
			\n[Mandelbrot] [Julia] [BurningShip] [Uterus] [Quasi_heart] \
[Vertical]\n"));
		exit(EXIT_FAILURE);
	}
}

int		main(int ac, char **av)
{
	check_intra(ac, av);
	init(av[1]);
	return (0);
}
