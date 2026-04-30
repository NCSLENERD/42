/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:12:06 by nmayela           #+#    #+#             */
/*   Updated: 2025/12/09 17:12:07 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr_base(int n, char *base, int *res)
{
	int				c;
	unsigned int	u;
	unsigned int	len_base;

	if (!base)
		return ;
	len_base = 0;
	while (base[len_base])
		len_base++;
	u = (unsigned int) n;
	if (u < len_base)
	{
		c = (u % len_base);
		ft_putchar_fd(base[c], 1, res);
		return ;
	}
	ft_putnbr_base((u / len_base), base, res);
	c = (u % len_base);
	ft_putchar_fd(base[c], 1, res);
}
