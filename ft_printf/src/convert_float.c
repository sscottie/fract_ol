/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 00:42:04 by sscottie          #+#    #+#             */
/*   Updated: 2019/10/07 10:48:19 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_round_number(long double num, char *fraction,
							int i, char *exponent)
{
	int		temp;

	num *= 10.0;
	temp = (int)num;
	if (temp > 4)
	{
		if (fraction[i] == '9')
		{
			fraction[i] = '0';
			while (fraction[--i] == '9')
				fraction[i] = '0';
			if (fraction[i] == '.')
			{
				i = 0;
				while (exponent[i] != '\0')
					i++;
				exponent[--i]++;
			}
			else
				fraction[i]++;
		}
		else
			fraction[i]++;
	}
}

static char	*ft_convert_fraction(long double num, long long int temp,
									int *precision, char *exponent)
{
	char	*fraction;
	int		i;

	temp = (long long int)num;
	num -= (long double)temp;
	if ((fraction = (char*)malloc(sizeof(char) * (*precision + 2))) == NULL)
		exit(-1);
	fraction[*precision + 1] = '\0';
	fraction[0] = '.';
	i = 1;
	while (i <= (*precision))
	{
		num *= 10.0;
		temp = (int)num;
		fraction[i++] = temp + '0';
		num -= (long double)temp;
	}
	ft_round_number(num, fraction, --i, exponent);
	return (fraction);
}

char		*ft_convert_float(t_all *st, long double num)
{
	char	*exponent;
	char	*fraction;
	int		precision;
	char	*result;

	if (st->acc == 0)
		return (ft_itoa((int)ft_round(num, 0)));
	if ((exponent = ft_l_itoa((size_t)num)) == NULL)
		exit(-1);
	fraction = NULL;
	if (st->acc == 0)
		precision = 0;
	else
		precision = (st->acc == -1) ? 6 : st->acc;
	if (precision != 0)
		fraction = ft_convert_fraction(num, 0, &precision, exponent);
	if (fraction)
		result = ft_strjoin(exponent, fraction);
	else
		return (exponent);
	free(exponent);
	free(fraction);
	return (result);
}
