# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 17:07:52 by wwatkins          #+#    #+#              #
#    Updated: 2016/11/29 16:01:09 by wwatkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_display_file
SRC= ft_display_file.c function.c
OBJ= ft_display_file.o function.o

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra $(SRC)
	@gcc $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
