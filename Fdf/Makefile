# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/22 19:20:08 by wwatkins          #+#    #+#              #
#    Updated: 2016/03/02 16:00:16 by wwatkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/ ./lib/libft/include/
LIB_PATH = ./lib/libft/
MLX_PATH = ./lib/minilibx_macos

NAME = fdf
CC = gcc
CFLGS = -Werror -Wextra -Wall -Ofast
MLXFLGS = -L$(MLX_PATH) -I$(MLX_PATH) -lmlx \
		  -framework OpenGL -framework AppKit

SRC_NAME  = main.c core.c draw.c triangle.c parse.c hook.c

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(LIB_PATH)$(LIB_NAME)

.PHONY: re all nolib clean fclean cleanmlx cleanlib fcleanlib norme

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX_PATH) re
	make -C $(LIB_PATH) re
	$(CC) $(CFLGS) $(LIB) $(INC) $(OBJ) $(MLXFLGS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLGS) $(INC) -o $@ -c $<

nolib:
	$(CC) $(CFLGS) -L$(LIB_PATH) -lft $(SRC) $(INC) $(OBJ) $(MLXFLGS) -o $(NAME)

cleanmlx:
	make -C $(MLX_PATH) clean

cleanlib:
	make -C $(LIB_PATH) clean

fcleanlib:
	make -C $(LIB_PATH) fclean

clean: cleanmlx cleanlib
	rm -fv $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean fcleanlib
	rm -fv $(NAME)

re: fclean all

norme:
	make -C $(LIB_PATH) norme
	norminette $(SRC) ./include/fdf.h
