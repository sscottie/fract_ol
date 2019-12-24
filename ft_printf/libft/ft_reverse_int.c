/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:07:17 by sscottie          #+#    #+#             */
/*   Updated: 2019/10/06 18:51:15 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_reverse_int(int nbr)
{
	int reverse;

	reverse = 0;
	while (nbr != 0)
	{
		reverse = reverse * 10;
		reverse = reverse + nbr % 10;
		nbr = nbr / 10;
	}
	return (reverse);
}
