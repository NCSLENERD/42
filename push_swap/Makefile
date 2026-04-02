# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/20 19:38:35 by nmayela           #+#    #+#              #
#    Updated: 2026/03/20 19:38:35 by nmayela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = pushswap
SRC = push_swap.c ft_putnbr_fd.c push_swap_utils.c push_swap_utils2.c push_swap_utils3.c list_utils.c list_utils2.c ft_atoi.c push_swap_utils4.c
OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean	
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re