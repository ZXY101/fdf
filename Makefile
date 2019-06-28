# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stenner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/27 17:28:44 by stenner           #+#    #+#              #
#    Updated: 2019/06/28 11:55:24 by stenner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT_PATH = ./libft/

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make -C $(LIBFT_PATH) 

clean:
	@make -C $(LIBFT_PATH)/ clean

fclean: clean
	@make -C $(LIBFT_PATH)/ fclean

re: fclean all

.PHONY: all fclean clean re
