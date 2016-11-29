# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 16:59:38 by wwatkins          #+#    #+#              #
#    Updated: 2016/11/23 16:59:44 by wwatkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ./srcs/ft_putchar.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c \
	  ./srcs/ft_putstr.c ./srcs/ft_swap.c
LIB = ft_putchar.o ft_strcmp.o ft_strlen.o ft_putstr.o ft_swap.o

all: $(NAME)

$(NAME):
	@gcc -c -I ./includes/ -Wall -Werror -Wextra $(SRC)
	@ar rc $(NAME) $(LIB)
	@ranlib $(NAME)

clean:
	@rm -f $(LIB)

fclean: clean
	@rm -f $(NAME)

re: fclean all
