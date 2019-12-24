/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_cl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:39:35 by sscottie          #+#    #+#             */
/*   Updated: 2019/11/12 17:06:38 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_CL_H
# define VAR_CL_H

# define WIDTH 1920
# define HEIGHT 1080

typedef struct	s_var
{
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	int			max_iter;
	double		cx;
	double		cy;
	int			color;
}				t_var;

#endif
