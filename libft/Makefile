# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elchouai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 17:26:45 by elchouai          #+#    #+#              #
#    Updated: 2019/02/21 18:58:48 by elchouai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC_C = *.c
FT_O = *.o

.PHONY: clean fclean re all

all: $(NAME)

$(FT_O):
	@gcc -Wall -Wextra -Werror -c $(SRC_C)

$(NAME): $(FT_O)
	@ar rc $(NAME) $(FT_O)
	@ranlib $(NAME)

clean:
	@/bin/rm -rf $(FT_O)

fclean: clean
	@/bin/rm -rf $(NAME)
	
re: fclean all
