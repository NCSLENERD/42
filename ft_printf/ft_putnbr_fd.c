/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 22:54:45 by nmayela           #+#    #+#             */
/*   Updated: 2025/12/09 22:54:46 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd, int *res)
{
	char	c;

	if (n == -2147483648)
	{
		ft_putstr_fd_mod("-2147483648", fd, res);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd, res);
	}
	if (n < 10)
	{
		c = (n % 10) + '0';
		ft_putchar_fd(c, fd, res);
		return ;
	}
	ft_putnbr_fd((n / 10), fd, res);
	c = (n % 10) + '0';
	ft_putchar_fd(c, fd, res);
}
