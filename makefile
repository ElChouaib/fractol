# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elchouai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 18:43:37 by elchouai          #+#    #+#              #
#    Updated: 2019/03/06 20:42:16 by elchouai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = *.c

RED=\033[0;32m
NC=\033[0m

OBJ = *.o

LIBFT =	libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		@gcc $(FLAGS)  -I /usr/local/include $(SRC)  -o $(NAME) $(LIBFT)  -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
		@echo "Creating fractol: ${RED} OK ${NC}";
$(OBJ): $(LIBFT)
		@$(CC) $(FLAGS) -c $(SRC)
		@echo "Compiling project: ${RED} OK ${NC}";
$(LIBFT):
		@make -C ./libft/
		@echo "Compiling Libft: ${RED} OK ${NC}";
clean:
		@rm -f $(OBJ)
			@make clean -C ./libft/
		@echo "Deleting  objects files: ${RED} OK ${NC}";
fclean: clean
		@rm -f $(NAME)
			@make fclean -C ./libft/
		@echo "Deleting executable files: ${RED} OK ${NC}";

re: fclean all

.PHONY : all, re, clean, flcean
