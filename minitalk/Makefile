CC = cc
CFLAGS = -Wextra -Werror -Wall
NAME_CLIENT = client
NAME_SERVER = server
SRC_CLIENT = client.c ft_atoi.c
SRC_SERVER = server.c ft_printf.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd_mod.c ft_putnbr_unsigned.c ft_putnbr_base.c ft_putnbr_base_ptr.c  

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_CLIENT): $(SRC_CLIENT)
	$(CC) $(CFLAGS) $(SRC_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER): $(SRC_SERVER)
	$(CC) $(CFLAGS) $(SRC_SERVER) -o $(NAME_SERVER)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all re clean fclean