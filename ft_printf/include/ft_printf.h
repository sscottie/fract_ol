/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 19:35:27 by sscottie          #+#    #+#             */
/*   Updated: 2019/10/08 21:50:38 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include "libft.h"

# define RED(string)     "\e[0;31m" string "\x1b[0m"
# define GREEN(string)   "\e[0;32m" string "\x1b[0m"
# define YELLOW(string)  "\e[0;33m" string "\x1b[0m"
# define BLUE(string)    "\e[0;34m" string "\x1b[0m"
# define PURPLE(string)  "\e[0;35m" string "\x1b[0m"
# define CYAN(string)    "\e[0;36m" string "\x1b[0m"
# define WHITE(string)   "\e[0;37m" string "\x1b[0m"
# define SIZE 100000

/*
** %[flags][len][.acc][size]type
*/

typedef struct		s_all
{
	char			flag[3];
	char			*fmt;
	char			*fmt_cp;
	int				i;
	va_list			args;
	int				len;
	int				acc;
	char			size;
	char			type;
	int				count;
	int				sign;
}					t_all;

t_all				*init_st(t_all *st);
int					ft_printf(const char *fmt, ...);
void				reinit_st(t_all *st);
int					parse(t_all *st);
int					pre_format(t_all *st);
void				fill_flags(t_all *st);
void				fill_len_acc(t_all *st);
void				fill_size(t_all *st);
void				do_for_string(t_all *st);
void				string_with_flags(t_all *st, char *s, int len);
void				do_for_char(t_all *st);
void				do_for_percent(t_all *st);
void				do_for_int(t_all *st);
void				do_for_u_int(t_all *st);
void				u_int_with_flags(t_all *st, char *s, int len);
void				do_for_oct(t_all *st);
void				do_for_hex(t_all *st);
void				do_for_pointer(t_all *st);
void				null_p_with_acc(t_all *st);
void				do_for_null(t_all *st);
void				null_with_acc(t_all *st);
void				crossroad_for_int(t_all *st);
void				crossroad_for_u(t_all *st);
void				crossroad_for_oct(t_all *st);
void				crossroad_for_hex(t_all *st);
void				crossroad_for_floats(t_all *st);
void				do_for_hh_int(t_all *st);
void				do_for_h_int(t_all *st);
void				do_for_l_int(t_all *st);
void				do_for_ll_int(t_all *st);
void				oct_with_flags(t_all *st, char *s, int len);
void				poiner_with_flags(t_all *st, char *s, int len);
char				*fill_with_hex(t_all *st, char *s, int len);
void				fill_with_oct(t_all *st, char **s, int len);
void				hex_with_flags(t_all *st, char *s, int len);
void				do_for_positive(t_all *st, char *s, int len);
void				do_for_negative(t_all *st, char *s, int len);
void				int_with_flags(t_all *st, char *s, int len);
char				*check_letter(char *s, t_all *st);
void				do_for_hh_uns(t_all *st);
void				do_for_h_uns(t_all *st);
void				do_for_l_uns(t_all *st);
void				do_for_ll_uns(t_all *st);
void				do_for_hh_oct(t_all *st);
void				do_for_h_oct(t_all *st);
void				do_for_l_oct(t_all *st);
void				do_for_ll_oct(t_all *st);
void				do_for_hh_hex(t_all *st);
void				do_for_h_hex(t_all *st);
void				do_for_l_hex(t_all *st);
void				do_for_ll_hex(t_all *st);
void				do_for_floats(t_all *st);
void				do_for_l_floats(t_all *st);
int					ft_fwrite(const char flag, const char *input, size_t len);
int					ft_fwrite_c(const char flag, const char *input, size_t len);
char				*ft_convert_float(t_all *st, long double num);
void				do_for_positive_hex(t_all *st, char *s, int len);
void				insert_flag_2(t_all *st);
void				null_with_hex(t_all *st);
void				null_with_no_acc_hex(t_all *st);
void				foo(char **s, t_all *st, int *len);
void				do_for_u_no_flags(t_all *st, char *s, int len);
void				put_number_with_minus(t_all *st, int len, char *s);
void				put_number_with_flag(t_all *st, int len, char *s);
void				put_null(t_all *st);

#endif
