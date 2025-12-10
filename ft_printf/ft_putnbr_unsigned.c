/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:11:56 by nmayela           #+#    #+#             */
/*   Updated: 2025/12/09 17:12:01 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, int *res)
{
	char	c;

	if (n < 10)
	{
		c = (n % 10) + '0';
		ft_putchar_fd(c, 1, res);
		return ;
	}
	ft_putnbr_unsigned((n / 10), res);
	c = (n % 10) + '0';
	ft_putchar_fd(c, 1, res);
}
