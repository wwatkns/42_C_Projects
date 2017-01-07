# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 17:14:43 by wwatkins          #+#    #+#              #
#    Updated: 2017/01/06 10:40:19 by wwatkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE), )
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
SYMB = libft_malloc.so
CC = gcc

SRC_PATH = ./src/
OBJ_PATH = ./obj/
LIB_PATH =
INC_PATH = ./include/ ./libft/include/ ./libftprintf/include

# CC_FLAGS = -Werror -Wextra -Wall -fPIC
CC_FLAGS = -Werror -Wextra -Wall

SRC_NAME = malloc.c free.c realloc.c utils.c show_alloc_mem.c

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft libftprintf
LIB_INCL = -lft -lftprintf

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L$(LIB_PATH),$(LIB_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_PATH)libft -j
	make -C $(LIB_PATH)libftprintf -j
	# $(CC) $(CC_FLAGS) -dynamiclib -o $(NAME) $(LIB_INCL) $^ $(LIB)
	$(CC) $(CC_FLAGS) -shared -o $(NAME) $(LIB_INCL) $^ $(LIB)
	ln -sf $(NAME) $(SYMB)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LIB_PATH)libft fclean
	make -C $(LIB_PATH)libftprintf fclean
	rm -fv $(NAME) $(SYMB)

re: fclean all
