# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmayela <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/27 19:05:20 by nmayela           #+#    #+#              #
#    Updated: 2026/04/27 19:05:21 by nmayela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wextra -Wall
NAME = so_long
SRC = flood_fill.c parse_map.c utils.c verif_content.c verif_struct.c so_long.c get_nextline/get_next_line_utils.c get_nextline/get_next_line.c render.c events.c ft_printf/ft_putchar_fd.c ft_printf/ft_putnbr_base.c ft_printf/ft_putnbr_base_ptr.c  ft_printf/ft_putnbr_fd.c ft_printf/ft_putnbr_unsigned.c ft_printf/ft_putstr_fd_mod.c ft_printf/ft_printf.c
OBJ = $(SRC:.c=.o)
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

all : $(NAME)
$(NAME) : $(MLX_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB) :
	$(MAKE) -C $(MLX_DIR)

%.o:	%.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean	
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re