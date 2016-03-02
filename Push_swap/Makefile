# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/25 10:30:40 by wwatkins          #+#    #+#              #
#    Updated: 2016/03/02 17:18:57 by wwatkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/ ./lib/libft/include/
LIB_PATH = ./lib/libft/

NAME = push_swap
CC = gcc
CFLGS = -Werror -Wextra -Wall
FNCTION = $(shell ls -l $(LIB_PATH)/src | grep ft_ | sed 's/^.*ft_//' | sed 's/..$$//')
FORBID = printf $(FNCTION)

SRC_NAME = main.c move_swap.c move_push.c move_rotate.c move_reverse_rotate.c \
		   utils.c resolve.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(LIB_PATH)$(LIB_NAME)
FN1 = $(addprefix -e $\" ,$(addsuffix $\", $(FORBID)))
FN2 = $(addprefix -e $\"	,$(addsuffix $\", $(FORBID)))

.PHONY: re all clean fclean cleanlib fcleanlib check nolib norme

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_PATH) re
	$(CC) $(CFLGS) $(LIB) $(INC) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLGS) $(INC) -o $@ -c $<

nolib: $(OBJ)
	$(CC) $(CFLGS) $(LIB) $(INC) $(OBJ) -o $(NAME)

cleanlib:
	make -C $(LIB_PATH) clean

fcleanlib:
	make -C $(LIB_PATH) fclean

clean: cleanlib
	rm -fv $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean fcleanlib
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

norme:
	make -C $(LIB_PATH) norme
	norminette $(SRC) ./include/
