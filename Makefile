# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 17:17:19 by panderss          #+#    #+#              #
#    Updated: 2019/12/10 14:29:09 by panderss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_gnl

SRC = ./get_next_line.c

INCLUDES = ./includes/

OBJ = $(SRC:.c=.o)

all: lib $(NAME)

lib:
	make -C libft/ fclean && make -C libft/

$(NAME):
	gcc -Wall -Wextra -Werror -I libft/includes -o $(OBJ) -c $(SRC)
	gcc -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	gcc -o $(NAME) main.o $(OBJ) -I libft/includes -L libft/ -lft

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f main.o
	make -C libft/ fclean

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
