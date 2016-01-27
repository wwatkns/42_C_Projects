# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/27 14:31:06 by wwatkins          #+#    #+#              #
#    Updated: 2016/01/27 16:26:26 by wwatkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/

NAME = libvec.a
CC = gcc
CFGLAGS = -Werror -Wextra -Wall

SRC_NAME  = vector2.c vector2_op.c vector3.c vector3_op.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2>/dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(LIB) $(INC) -o $@ -c $<

norme:
	norminette $(SRC) $(INC_PATH)lib_vector.h

clean:
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	rm -f $(NAME)

re: fclean all
