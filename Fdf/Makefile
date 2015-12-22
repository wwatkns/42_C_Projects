# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/22 19:20:08 by wwatkins          #+#    #+#              #
#    Updated: 2015/12/22 19:36:26 by wwatkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/ ./libft/include
LIB_PATH = ./libft

NAME = fdf
CC = gcc
CFLGS = -Werror -Wextra -Wall
MLXFLGS = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL \
		   -framework AppKit

SRC_NAME  = main.c core.c line.c read.c
OBJ_NAME = $(SRC_NAME.c=.o)
LIB_NAME =  libft.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(LIB_PATH)$(LIB_NAME)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLGS) -L$(LIB_PATH) -lft $(SRC) $(INC) -o $(NAME) $(OBJ) $(MLXFLGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2>/dev/null || echo "" > /dev/null
	$(CC) $(CFLGS) $(LIB) $(INC) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY: re all clean fclean
