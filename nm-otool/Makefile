# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/21 10:57:38 by wwatkins          #+#    #+#              #
#    Updated: 2017/03/07 18:18:06 by wwatkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NM_NAME = ft_nm
OT_NAME = ft_otool

OBJS_PATH = ./obj/
SRCS_PATH = ./srcs/
INCS_PATH = ./includes/
LIBS_PATH = ./libs/

NM_SRCS_NAME = ft_nm.c core.c magic.c mach.c utils.c mach_x64.c symbol.c \
			   mach_x86.c fat.c list.c output.c ar.c

OT_SRCS_NAME = ft_otool.c core.c magic.c mach.c utils.c mach_x64.c symbol.c \
			   mach_x86.c fat.c list.c output.c ar.c

NM_OBJS_NAME = $(NM_SRCS_NAME:.c=.o)
OT_OBJS_NAME = $(OT_SRCS_NAME:.c=.o)

NM_OBJ = $(addprefix $(OBJS_PATH), $(NM_OBJS_NAME))
OT_OBJ = $(addprefix $(OBJS_PATH), $(OT_OBJS_NAME))

CC = clang
CFLAGS = -Wall -Werror -Wextra
# CFLAGS = -g

LIBFT_PATH = $(LIBS_PATH)libft
LIBPT_PATH = $(LIBS_PATH)libftprintf
LIBFT_ARCH = $(LIBFT_PATH)/libft.a
LIBPT_ARCH = $(LIBPT_PATH)/libftprintf.a
LIB_CMDS = $(addprefix -I, $(LIBFT_PATH) $(LIBPT_PATH))
LIB_INCS = $(addsuffix /include, $(LIB_CMDS))

all: omkdir $(NM_NAME) $(OT_NAME)

omkdir:
	mkdir -p $(OBJS_PATH)

$(NM_NAME): $(LIBFT_ARCH) $(LIBPT_ARCH) $(NM_OBJ)
	$(CC) $(CFLAGS) $(NM_OBJ) $(LIBFT_ARCH) $(LIBPT_ARCH) -o $(NM_NAME)

$(OT_NAME): $(LIBFT_ARCH) $(LIBPT_ARCH) $(OT_OBJ)
	$(CC) $(CFLAGS) $(OT_OBJ) $(LIBFT_ARCH) $(LIBPT_ARCH) -o $(OT_NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(LIB_INCS) -I$(INCS_PATH)

$(LIBFT_ARCH):
	make -C $(LIBFT_PATH)

$(LIBPT_ARCH):
	make -C $(LIBPT_PATH)

clean:
	rm -rf $(OBJS_PATH)
	make -C $(LIBFT_PATH) clean
	make -C $(LIBPT_PATH) clean

fclean: clean
	rm -rf $(NM_NAME) $(OT_NAME)
	make -C $(LIBFT_PATH) fclean
	make -C $(LIBPT_PATH) fclean

re: fclean all
