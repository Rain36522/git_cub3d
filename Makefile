# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csil <csil@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 08:09:16 by pudry             #+#    #+#              #
#    Updated: 2023/12/16 09:11:15 by csil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

MLX = mlx/libmlx.a
INCLUDES = -I/opt/X11/include -Imlx
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit


BLUE = \\033[1;34m
WHITE = \\033[0;37m
YELLOW = \\033[0;33m
RED = \\033[1;31m
GREEN = \\033[1;32m
BRWN = \\033[0; 33m
GREY = \\033[1;30m

#utils/ft_check_map.c utils/ft_stock_map.c
GNL = gnl/get_next_line.c gnl/get_next_line_utils.c

SRC = src/main.c src/input_in_list.c src/input_in_list_3.c src/input_in_list_2.c \
	src/put_map.c src/key_hook.c

UTL = utils/print_var.c utils/ft_utils_mlx.c utils/ft_calcul.c

# $(GNL:.c=.o)
OBJ = $(GNL:.c=.o) $(SRC:.c=.o) $(UTL:.c=.o)

all : lib $(NAME)
	./cub3d

.c.o:
	$(CC) $(FLAGS) -c -o $@ $< $(INCLUDES)
	
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

lib :
	@make -C libft/
	@make -C mlx/

clean :
	@rm -f $(OBJ)
	@make clean -C libft/

fclean : clean
	@rm -f $(NAME)
	@make fclean -C libft/

re : fclean all

gen_obj :
	@$(CC) $(CFLAGS) -c $(SRC) $(GNL) $(SRC)

header :
	@echo "	      .-~~~-.        ${GREY}||${BLUE}::::::${RED}==========${WHITE}"
	@echo "	     /= ___  \       ${GREY}||${BLUE}::::::${WHITE}=========="
	@echo "	    |- /~~~\  |      ${GREY}||${BLUE}::::::${RED}==========${WHITE}"
	@echo "	    |=( ^.^ ) |      ${GREY}||${WHITE}================"
	@echo "	    \__\_=_/__/      ${GREY}||${RED}================${WHITE}"
	@echo "	     {_______}       ${GREY}||${WHITE}================"
	@echo "	   /  *       ~ --._ ${GREY}||${WHITE}"
	@echo "	  /= .     [] .     |  >"
	@echo "	 /  /|ooo     |  --^ ${GREY}||${WHITE}"
	@echo "	(   )\_______/       ${GREY}||${WHITE}"
	@echo "	 \..\//       \      ${GREY}||${WHITE}"
	@echo "	  ^-| ==    \_|      ${GREY}||${WHITE}"
	@echo "	    /         |      ${GREY}||${WHITE}"
	@echo "	   |=   >\  __/      ${GREY}||${WHITE}"
	@echo "	   \   \ |- --|      ${GREY}||${WHITE}"
	@echo "	    \ __| \___/      ${GREY}||${WHITE}"
	@echo "	     [__] _[__]      ${GREY}||${WHITE}"
	@echo "	   (    )(    )      ${GREY}||${WHITE}"
	@echo "	^^~ ^^^^^  ^^^^  ~^^^~^^~~~^^^~^^^~^^^~^^~^"




.PHONY : fclean re all header clean cnt check leak map