# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwatkins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 09:24:09 by wwatkins          #+#    #+#              #
#    Updated: 2016/01/20 09:35:09 by wwatkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/ ./libft/include/
LIB_PATH = ./libft
MLX_PATH = ./minilibx_macos

NAME = wolf3d
CC = gcc
CFLGS = -Werror -Wextra -Wall
MLXFLGS = -L$(MLX_PATH) -I$(MLX_PATH) -lmlx \
		  -framework OpenGL -framework AppKit
FNCTION = $(shell ls -l $(LIB_PATH)/src | grep ft_ | sed 's/^.*ft_//' | sed 's/..$$//')
FORBID = printf $(FNCTION)

SRC_NAME  = main.c draw.c core.c hook.c vector.c vector_op.c map.c
OBJ_NAME = $(SRC_NAME.c=.o)
LIB_NAME =  libft.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(LIB_PATH)$(LIB_NAME)
FBN = $(addprefix -e $\" ,$(addsuffix $\", $(FORBID)))

.PHONY: re all clean fclean cleanmlx cleanlib fcleanlib check nolib norme

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX_PATH) re
	make -C $(LIB_PATH) re
	$(CC) $(CFLGS) -L$(LIB_PATH) -lft $(SRC) $(INC) -o $(NAME) $(OBJ) $(MLXFLGS)

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
	@ls | grep -q auteur && cat -e auteur | grep -q $(USER)$ && echo \
	"    Auteur [\033[32mOK\033[0m]" || echo "    Auteur [\033[31mKO\033[0m]"
	@cat $(SRC) | grep -q $(FBN) && echo " Forbidden [\033[31mKO\033[0m]" ||\
	echo " Forbidden [\033[32mOK\033[0m]"
	@ls | grep -q -U $(NAME) && echo "Executable [\033[32mOK\033[0m]" ||\
	echo "Executable [\033[31mKO\033[0m]"
	@$(MAKE) norme | grep -B 1 Error && echo "     Norme [\033[31mKO\033[0m]" || \
	echo "     Norme [\033[32mOK\033[0m]"
	@ls $(LIB_PATH) | grep -q $(LIB_NAME) && echo "     Libft [\033[32mOK\033[0m]" ||\
	echo "     Libft [\033[31mKO\033[0m]"
	@ls $(MLX_PATH) | grep -q libmlx.a && echo "       Mlx [\033[32mOK\033[0m]" ||\
	echo "       Mlx [\033[31mKO\033[0m]"

norme:
	make -C $(LIB_PATH) norme
	norminette $(SRC) ./include/
