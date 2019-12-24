# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 18:10:05 by rdonnor           #+#    #+#              #
#    Updated: 2019/11/03 00:40:05 by sscottie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY: debug all clean fclean re
HEADDERS = libft.h ft_printf.h get_next_line.h
VPATH = libft:src/:include
FT_PRINTF = libftprintf.a
LIBFT = libft.a
CFLAGS = -Wall -Werror -Wextra
HEADER = -I include

OBJ_DIR = obj/

LFT_SRC =   ft_abs.c \
            ft_atoi.c \
            ft_atoi_base.c \
            ft_bzero.c \
            ft_intsize.c \
            ft_is_power_of_n.c \
            ft_isalnum.c \
            ft_isalpha.c \
            ft_isascii.c \
            ft_isdigit.c \
            ft_isnan.c \
            ft_isprint.c \
            ft_itoa.c \
            ft_itoa_base.c \
            ft_l_itoa.c \
            ft_l_itoa_base.c \
            ft_ll_itoa.c \
            ft_ll_itoa_base.c \
            ft_lstadd.c \
            ft_lstdel.c \
            ft_lstdelone.c \
            ft_lstiter.c \
            ft_lstmap.c \
            ft_lstnew.c \
            ft_memalloc.c \
            ft_memccpy.c \
            ft_memchr.c \
            ft_memcmp.c \
            ft_memcpy.c \
            ft_memdel.c \
            ft_memmove.c \
            ft_memset.c \
            ft_pow.c \
            ft_power.c \
            ft_print_bits.c \
            ft_putchar.c \
            ft_putchar_fd.c \
            ft_putendl.c \
            ft_putendl_fd.c \
            ft_putnbr.c \
            ft_putnbr_fd.c \
            ft_putstr.c \
            ft_putstr_fd.c \
            ft_reverse_bits.c \
            ft_reverse_int.c \
            ft_round.c \
            ft_strcat.c \
            ft_strchr.c \
            ft_strclr.c \
            ft_strcmp.c \
            ft_strcpy.c \
            ft_strdel.c \
            ft_strdup.c \
            ft_strequ.c \
            ft_striter.c \
            ft_striteri.c \
            ft_strjoin.c \
            ft_strjoinfree.c \
            ft_strlcat.c \
            ft_strlen.c \
            ft_strmap.c \
            ft_strmapi.c \
            ft_strncat.c \
            ft_strnchr.c \
            ft_strncmp.c \
            ft_strncpy.c \
            ft_strnequ.c \
            ft_strnew.c \
            ft_strnstr.c \
            ft_strrchr.c \
            ft_strrev.c \
            ft_strsplit.c \
            ft_strstr.c \
            ft_strsub.c \
            ft_strtrim.c \
            ft_swap.c \
            ft_swap_bits.c \
            ft_tolower.c \
            ft_toupper.c \
            get_next_line.c

PF_SRC =	convert_float.c \
            crossroads.c \
            do_for_char.c \
            do_for_floats.c \
            do_for_hex.c \
            do_for_int.c \
            do_for_null.c \
            do_for_oct.c \
            do_for_pointer.c \
            do_for_sized_hex.c \
            do_for_sized_int.c \
            do_for_sized_oct.c \
            do_for_sized_u.c \
            do_for_string.c \
            do_for_u_int.c \
            format.c \
            ft_fwrite.c \
            ft_printf.c \
            help_funcs.c \
            init_st.c \
            parse.c \

PF_OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(PF_SRC)))
LFT_OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(LFT_SRC)))

all: $(FT_PRINTF)

GOALS = all $(LIBFT) $(FT_PRINTF) re fclean clean

debug:: override CFLAGS =-g
ifneq ($(MAKECMDGOALS),$(GOALS))
debug:: all
endif

$(FT_PRINTF):: $(OBJ_DIR)
$(FT_PRINTF):: $(LFT_OBJ) $(PF_OBJ) $(GNL_OBJ)
	@ar rc $@ $^

$(LIBFT):: $(OBJ_DIR)
$(LIBFT):: $(LFT_OBJ) $(GNL_OBJ)
	@ar rc $@ $^

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(HEADDERS)
	gcc $(CFLAGS) -c $< -o $@ $(HEADER)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(FT_PRINTF)

re: fclean all