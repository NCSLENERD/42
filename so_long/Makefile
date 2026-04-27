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
CFLAGS = -Werror - Wextra - Wall
NAME = so_long
SRC = flood_fill.c parse_map.c utils.c verif_content.c verif_struct.c so_long.cc
OBJ = (SRC:.c=.o)

all : $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean	
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re