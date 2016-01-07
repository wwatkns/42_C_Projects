# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/22 19:20:08 by wwatkins          #+#    #+#              #
#    Updated: 2016/01/07 09:38:02 by wwatkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/ ./libft/include/
LIB_PATH = ./libft
MLX_PATH = ./minilibx_macos

NAME = fdf
CC = gcc
CFLGS = -Werror -Wextra -Wall -o3
MLXFLGS = -L$(MLX_PATH) -I$(MLX_PATH) -lmlx \
		  -framework OpenGL -framework AppKit

SRC_NAME  = main.c core.c draw.c parse.c hook.c
OBJ_NAME = $(SRC_NAME.c=.o)
LIB_NAME =  libft.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(LIB_PATH)$(LIB_NAME)

.PHONY: re all clean fclean cleanmlx cleanlib fcleanlib norme

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX_PATH) re
	make -C $(LIB_PATH) re
	$(CC) $(CFLGS) -L$(LIB_PATH) -lft $(SRC) $(INC) -o $(NAME) $(OBJ) $(MLXFLGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2>/dev/null || echo "" > /dev/null
	$(CC) $(CFLGS) $(LIB) $(INC) -o $@ -c $<

cleanmlx:
	make -C $(MLX_PATH) clean

cleanlib:
	make -C $(LIB_PATH) clean

fcleanlib:
	make -C $(LIB_PATH) fclean

clean: cleanmlx cleanlib
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean fcleanlib
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
