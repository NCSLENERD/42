/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:51:28 by nmayela           #+#    #+#             */
/*   Updated: 2025/11/30 13:51:30 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*int main(void)
{
	int fd_test = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	ft_putchar_fd('b', fd_test);
	ft_putchar_fd('o', fd_test);
	ft_putchar_fd('n', fd_test);
	ft_putchar_fd('j', fd_test);
	close(fd_test);
}*/