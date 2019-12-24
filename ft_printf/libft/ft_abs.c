/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:35:45 by rdonnor           #+#    #+#             */
/*   Updated: 2019/10/08 21:47:25 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long			ft_abs(int x)
{
	if (x < 0)
		return (x *= -1);
	else
		return (x);
}

long long int	ft_llabs(long long x)
{
	if (x < 0)
		return (x *= -1);
	else
		return (x);
}

long int		ft_labs(long int x)
{
	if (x < 0)
		return (x *= -1);
	else
		return (x);
}

long double		ft_fabsl(long double x)
{
	if (x < 0)
		return (x *= -1);
	else
		return (x);
}

double			ft_fabs(double x)
{
	if (x < 0)
		return (x *= -1);
	else
		return (x);
}
