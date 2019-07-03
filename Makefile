# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stenner <stenner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/27 17:28:44 by stenner           #+#    #+#              #
#    Updated: 2019/07/03 12:00:31 by stenner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT_PATH = ./libft/

SRC_PATH = ./src/

SRC_NAME = main.c \
	   	   draw_line.c \
		   images.c \
		   gfx_utility.c \
		   handle_hooks.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

SRCO = $(patsubst %.c, %.o, $(SRC))

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCO)
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) $(SRCO) $(INC) -L $(LIBFT_PATH) -lft -o $(NAME) $(MLX_FLAGS)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m Created.\033[0m"

$(SRC_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@make -C $(LIBFT_PATH)/ clean
	@/bin/rm -rf $(SRCO)
	@echo "\033[31mObjects Files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31mRemoved.\033[0m"

fclean: clean
	@make -C $(LIBFT_PATH)/ fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m Removed.\033[0m"

re: fclean all

.PHONY: all fclean clean re
