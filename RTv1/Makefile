# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/28 10:58:16 by wwatkins          #+#    #+#              #
#    Updated: 2016/03/06 11:20:10 by wwatkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/ ./lib/libft/include/ ./lib/libvec/include
LIB_PATH = ./lib/libft/
VEC_PATH = ./lib/libvec/
MLX_PATH = ./lib/minilibx_macos

NAME = rtv1
CC = gcc
CFLGS = -Werror -Wextra -Wall -Ofast
MLXFLGS = -L$(MLX_PATH) -I$(MLX_PATH) -lmlx \
		  -framework OpenGL -framework AppKit
FNCTION = $(shell ls -l $(LIB_PATH)/src | grep ft_ | sed 's/^.*ft_//' | sed 's/..$$//')
FORBID = printf $(FNCTION)

SRC_NAME = main.c parse.c utils.c core.c hook.c draw.c raytracing.c \
		   rayintersect.c light.c init.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft.a
VEC_NAME = libvec.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(LIB_PATH)$(LIB_NAME)
VEC = $(VEC_PATH)$(VEC_NAME)
FN1 = $(addprefix -e $\" ,$(addsuffix $\", $(FORBID)))
FN2 = $(addprefix -e $\"	,$(addsuffix $\", $(FORBID)))

.PHONY: re all clean fclean cleanmlx cleanvec fcleanvec cleanlib \
		fcleanlib check nolib norme

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX_PATH) re
	make -C $(VEC_PATH) re
	make -C $(LIB_PATH) re
	$(CC) $(CFLGS) $(LIB) $(VEC) $(INC) $(OBJ) $(MLXFLGS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLGS) $(INC) -o $@ -c $<

nolib: $(OBJ)
	$(CC) $(CFLGS) $(LIB) $(VEC) $(INC) $(OBJ) $(MLXFLGS) -o $(NAME)

cleanmlx:
	make -C $(MLX_PATH) clean

cleanlib:
	make -C $(LIB_PATH) clean

cleanvec:
	make -C $(VEC_PATH) clean

fcleanvec:
	make -C $(VEC_PATH) fclean

fcleanlib:
	make -C $(LIB_PATH) fclean

clean: cleanmlx cleanlib cleanvec
	rm -fv $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean fcleanlib fcleanvec
	rm -fv $(NAME)

re: fclean all

check:
	@ls | grep -q auteur && cat -e auteur | grep -q $(USER)$ && echo \
	"    Auteur [\033[32mOK\033[0m]" || echo "    Auteur [\033[31mKO\033[0m]"
	@cat $(SRC) | grep -q $(FN1) $(FN2) && echo " Forbidden [\033[31mKO\033[0m]" ||\
	echo " Forbidden [\033[32mOK\033[0m]"
	@ls | grep -q -U $(NAME) && echo "Executable [\033[32mOK\033[0m]" ||\
	echo "Executable [\033[31mKO\033[0m]"
	@$(MAKE) norme | grep -B 1 Error && echo "     Norme [\033[31mKO\033[0m]" || \
	echo "     Norme [\033[32mOK\033[0m]"
	@ls $(LIB_PATH) | grep -q $(LIB_NAME) && echo "     Libft [\033[32mOK\033[0m]" ||\
	echo "     Libft [\033[31mKO\033[0m]"
	@ls $(VEC_PATH) | grep -q $(VEC_NAME) && echo "    Libvec [\033[32mOK\033[0m]" ||\
	echo "    Libvec [\033[31mKO\033[0m]"
	@ls $(MLX_PATH) | grep -q libmlx.a && echo "       Mlx [\033[32mOK\033[0m]" ||\
	echo "       Mlx [\033[31mKO\033[0m]"

norme:
	make -C $(LIB_PATH) norme
	make -C $(VEC_PATH) norme
	norminette $(SRC) ./include/
