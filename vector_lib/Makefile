NAME = vector_lib.a

SRC_PATH = ./src/

SRC_NAME =	vector_matrix_multiply.c \
			vector_add.c \
			vector_subtract.c \
			vector_multiply.c \
			vector_divide.c \
			vector_dot_product.c \
			vector_length.c \
			vector_normalise.c \
			vector_cross_product.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

SRCO = $(patsubst %.c, %.o, $(SRC))

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCO)
	@ar rc $(NAME) $(SRCO)
	@echo "\033[36mVector Library Compiled."

$(SRC_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(SRCO)
	@echo "\033[94mVector Library Object Files Removed."

fclean: clean
	@rm -f $(NAME)
	@echo "\033[94mVector Library Removed."

re:	fclean all

.PHONY: all fclean clean re
