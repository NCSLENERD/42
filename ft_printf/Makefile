# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 17:10:14 by nmayela           #+#    #+#              #
#    Updated: 2025/12/09 17:35:16 by nmayela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = cc
CFLAGS = -Wall -Wextra -Werror 
NAME = libftprintf.a

SRC = ft_putnbr_base.c ft_putnbr_base_ptr.c ft_putnbr_unsigned.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd_mod.c ft_printf.c
OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re
