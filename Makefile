# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 00:49:15 by sscottie          #+#    #+#              #
#    Updated: 2019/11/12 02:48:34 by sscottie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: debug all clean fclean re

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RED_B = \033[1;4;31m
BLUE = \033[1;4;34m
RESET = \033[0m

HEADDERS =	fractol.h
VPATH =	ft_printf:src/:include
NAME =	fractol
PF =	libftprintf.a
MLX =	libmlx.a
CFLAGS = -Wall -Wextra -Werror -g
HEADER = -I include
MLX_HEAD = -I ./minilibx_macos/

MLX_DIR	=	./minilibx_macos/
PF_DIR =	./ft_printf/

OBJ_DIR = ./obj/
			
FT_SRC =	main.c \
			init.c \
			render.c \
			hooks.c

FT_OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(FT_SRC)))
PF_OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(LFT_SRC)))

all: $(NAME)

GOALS = all $(PF) $(MLX) $(NAME) re fclean clean

debug:: override CFLAGS =-g
ifneq ($(MAKECMDGOALS),$(GOALS))
debug:: all
endif

$(NAME):: $(OBJ_DIR)
$(NAME):: $(PF) $(MLX) $(FT_OBJ)
	@CC $(CFLAGS) -o $(NAME) $(FT_OBJ) $(HEADER) $(MLX_HEAD) ./ft_printf/libftprintf.a ./minilibx_macos/libmlx.a -framework OpenGL -framework AppKit -framework OpenCL
	@echo "$(BLUE)$(NAME):$(GREEN) $(NAME) was created$(RESET)"
	
$(PF)::
	@echo "$(BLUE)ft_printf:$(GREEN) Creating ft_printf ...$(RESET)"
	make -C $(PF_DIR)
	@echo "$(BLUE)ft_printf:$(GREEN) libftprintf.a is done$(RESET)"

$(MLX)::
	@echo "$(BLUE)MLX library:$(GREEN) Creating MLX library ...$(RESET)"
	make -C $(MLX_DIR)
	@echo "$(BLUE)MLX library:$(GREEN) libmlx.a is done$(RESET)"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)Object_derictory$(GREEN) is created $(RESET)"

$(OBJ_DIR)%.o: %.c $(HEADDERS)
	gcc $(CFLAGS) -c $< -o $@ $(HEADER) $(MLX_HEAD)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(PF_DIR)

fclean: clean
	@make fclean -C $(PF_DIR)
	@make clean -C $(MLX_DIR)
	@rm -f $(NAME)
	@rm -f $(MLX_DIR)$(MLX)

re: fclean all
