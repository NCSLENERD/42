/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbnr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:18:31 by nmayela           #+#    #+#             */
/*   Updated: 2025/11/30 14:18:35 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	if (n < 10)
	{
		c = (n % 10) + '0';
		write (fd, &c, 1);
		return ;
	}
	ft_putnbr_fd((n / 10), fd);
	c = (n % 10) + '0';
	write (fd, &c, 1);
}
/*int main(void)
{
	int fd_test = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	ft_putnbr_fd(2147483647,fd_test);
	close(fd_test);
	
}*/