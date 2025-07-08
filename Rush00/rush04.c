/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:13:48 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/06 16:11:19 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	r;
	int	c;

	r = 1;
	while (!(x <= 0) && !(y <= 0) && r <= y)
	{
		c = 1;
		while (c <= x)
		{
			if ((r == 1 && c == 1) || (r == y && c == x && x != 1 && y != 1))
				ft_putchar('A');
			else if ((r == y && c == 1) || (r == 1 && c == x))
				ft_putchar('C');
			else if (r > 1 && r < y && c > 1 && c < x)
				ft_putchar(' ');
			else
				ft_putchar('B');
			if (c == x)
				ft_putchar('\n');
			c++;
		}
		r++;
	}
	return ;
}
