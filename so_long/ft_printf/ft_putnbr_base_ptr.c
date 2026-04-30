/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:12:53 by nmayela           #+#    #+#             */
/*   Updated: 2025/12/09 17:12:56 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_putnbr_base_ulong(unsigned long n, char *base, int *res)
{
	int				c;
	unsigned long	u;
	unsigned long	len_base;

	if (!base)
		return ;
	len_base = 0;
	while (base[len_base])
		len_base++;
	u = (unsigned long) n;
	if (u < len_base)
	{
		c = (u % len_base);
		ft_putchar_fd(base[c], 1, res);
		return ;
	}
	ft_putnbr_base_ulong((u / len_base), base, res);
	c = (u % len_base);
	ft_putchar_fd (base[c], 1, res);
}

void	ft_putnbr_base_ptr(void *n, char *base, int *res)
{
	int				c;
	unsigned long	u;
	unsigned long	len_base;

	if (!base)
		return ;
	if (!n)
	{
		ft_putstr_fd_mod("(nil)", 1, res);
		return ;
	}
	ft_putstr_fd_mod("0x", 1, res);
	len_base = 0;
	while (base[len_base])
		len_base++;
	u = (unsigned long) n;
	if (u < len_base)
	{
		c = (u % len_base);
		ft_putchar_fd(base[c], 1, res);
		return ;
	}
	ft_putnbr_base_ulong((u / len_base), base, res);
	c = (u % len_base);
	ft_putchar_fd(base[c], 1, res);
}
