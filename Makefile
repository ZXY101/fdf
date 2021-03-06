# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stenner <stenner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/27 17:28:44 by stenner           #+#    #+#              #
#    Updated: 2019/07/22 11:29:45 by stenner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT_PATH = ./libft/

VEC_LIB_PATH = ./libvec/

MLX_PATH = ./minilibx_macos/

SRC_PATH = ./src/

SRC_NAME =	main.c \
			draw_line.c \
			images.c \
			gfx_utility.c \
			handle_hooks.c \
			handle_coords.c \
			mouse_key_release_down.c \
			keys.c \
			misc.c \
			cube.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

SRCO = $(patsubst %.c, %.o, $(SRC))

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lm
MLX_LFLAGS =  -lmlx -lXext -lX11 -lm

FLAGS = -Wall -Werror -Wextra

all: LIBFT VECLIB $(NAME)

LIBFT:
	@make -C $(LIBFT_PATH)

VECLIB:
	@make -C $(VEC_LIB_PATH)

$(LIBFT_PATH)libft.a:
	@make -C $(LIBFT_PATH)

$(VEC_LIB_PATH)libvec.a:
	@make -C $(VEC_LIB_PATH)

$(NAME): $(SRCO) $(LIBFT_PATH)libft.a $(VEC_LIB_PATH)libvec.a 
	@gcc $(FLAGS) $(SRCO) -L $(LIBFT_PATH) -lft -L $(VEC_LIB_PATH) -lvec -L $(MLX_PATH) -lmlx -o $(NAME) $(MLX_FLAGS)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m Created.\033[0m"

$(SRC_PATH)%.o: $(SRC_PATH)%.c includes/fdf.h
	@gcc $(FLAGS) -c $< -o $@

clean:
	@/bin/rm -rf $(SRCO)
	@echo "\033[31mObjects Files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31mRemoved.\033[0m"

fclean: clean
	@make -C $(LIBFT_PATH)/ fclean
	@make -C $(VEC_LIB_PATH)/ fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m Removed.\033[0m"

re: fclean all

.PHONY: all fclean clean re LIBFT VECLIB 
