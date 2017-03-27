# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwatkins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 09:24:09 by wwatkins          #+#    #+#              #
#    Updated: 2016/03/02 17:19:12 by wwatkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/ ./lib/libft/include/
LIB_PATH = ./lib/libft/
MLX_PATH = ./lib/minilibx_macos/

NAME = wolf3d
CC = gcc
CFLGS = -Werror -Wextra -Wall -Ofast
MLXFLGS = -L$(MLX_PATH) -I$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
FNCTION = $(shell ls -l $(LIB_PATH)/src | grep ft_ | sed 's/^.*ft_//' | sed 's/..$$//')
FORBID = printf $(FNCTION)

SRC_NAME = main.c draw.c core.c hook.c vector.c vector_op.c map.c raycast.c \
		   mouse_hook.c movement.c raycast_texture.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(LIB_PATH)$(LIB_NAME)
FB1 = $(addprefix -e $\" ,$(addsuffix $\", $(FORBID)))
FB2 = $(addprefix -e $\"	,$(addsuffix $\", $(FORBID)))

.PHONY: re all clean fclean cleanmlx cleanlib fcleanlib check nolib norme

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX_PATH) re
	make -C $(LIB_PATH) re
	$(CC) $(CFLGS) $(LIB) $(INC) $(OBJ) $(MLXFLGS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLGS) -I$(MLX_PATH) $(INC) -o $@ -c $<

nolib: $(OBJ)
	$(CC) $(CFLGS) -L$(LIB_PATH) $(LIB) $(INC) $(OBJ) $(MLXFLGS) -o $(NAME)

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

check:
	@ls | grep -q auteur && cat -e auteur | grep -q $(USER)$ && echo \
	"    Auteur [\033[32mOK\033[0m]" || echo "    Auteur [\033[31mKO\033[0m]"
	@cat $(SRC) | grep -q $(FB1) $(FB2) && echo " Forbidden [\033[31mKO\033[0m]" ||\
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
