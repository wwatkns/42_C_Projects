# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwatkins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 09:24:09 by wwatkins          #+#    #+#              #
#    Updated: 2016/01/14 11:53:08 by wwatkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/ ./libft/include/
LIB_PATH = ./libft
MLX_PATH = ./minilibx_macos

NAME = fractol
CC = gcc
CFLGS = -Werror -Wextra -Wall -o2
MLXFLGS = -L$(MLX_PATH) -I$(MLX_PATH) -lmlx \
		  -framework OpenGL -framework AppKit
FORBID = printf atoi

SRC_NAME  = main.c hook.c mousehook.c core.c draw.c fractal.c
OBJ_NAME = $(SRC_NAME.c=.o)
LIB_NAME =  libft.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(LIB_PATH)$(LIB_NAME)
FOR = $(addprefix -e , $(FORBID))

.PHONY: re all clean fclean cleanmlx cleanlib fcleanlib check nolib norme

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX_PATH) re
	make -C $(LIB_PATH) re
	$(CC) $(CFLGS) -L$(LIB_PATH) -lft $(SRC) $(INC) -o $(NAME) $(OBJ) $(MLXFLGS)
	$(MAKE) check

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2>/dev/null || echo "" > /dev/null
	$(CC) $(CFLGS) $(LIB) $(INC) -o $@ -c $<

nolib:
	$(CC) $(CFLGS) -L$(LIB_PATH) -lft $(SRC) $(INC) -o $(NAME) $(OBJ) $(MLXFLGS)

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

check:
	@ls | grep -q auteur && cat -e auteur | grep $(USER)$ && echo \
	"   Auteur [\033[32mOK\033[0m]" || echo "   Auteur [\033[31mKO\033[0m]"
	@ls | grep -q -U fractol && echo "  Fractol [\033[32mOK\033[0m]" ||\
	echo "  Fractol [\033[31mKO\033[0m]"
	@ls $(LIB_PATH) | grep -q libft.a && echo "    Libft [\033[32mOK\033[0m]" ||\
	echo "    Libft [\033[31mKO\033[0m]"
	@ls $(MLX_PATH) | grep -q libmlx.a && echo "      Mlx [\033[32mOK\033[0m]" ||\
	echo "      Mlx [\033[31mKO\033[0m]"
	cat $(SRC) | grep $(FOR) && echo "Forbidden [\033[31mKO\033[0m]" ||\
	echo "Forbidden [\033[32mOK\033[0m]"

norme:
	make -C $(LIB_PATH) norme
	norminette $(SRC) ./include/fractol.h
