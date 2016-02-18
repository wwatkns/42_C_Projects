# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/17 13:22:20 by wwatkins          #+#    #+#              #
#    Updated: 2016/02/18 11:17:41 by wwatkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_printf.a
FLAG= -Wall -Werror -Wextra
INCL= /ft_printf.h
SRC= ft_printf.c print_base.c print_str.c print_char.c print_int.c str_len.c \
	 print_unsigned_int.c print_mem.c parse_format.c get_flags.c get_width.c \
	 get_prec.c get_mod.c get_type.c
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

re: fclean all
