# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 14:56:55 by wwatkins          #+#    #+#              #
#    Updated: 2015/12/21 15:05:40 by wwatkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= lib2d.a
FLAG= -Wall -Werror -Wextra
INCL= /include/lib2d.h
SRC= assign.c draw.c color.c
OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAG) -I$(INCL) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

mclean: all clean

re: fclean all
