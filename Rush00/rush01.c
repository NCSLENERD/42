/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:20:00 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/06 16:34:20 by nmayela          ###   ########.fr       */
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
				ft_putchar('/');
			else if ((r == y && c == 1) || (r == 1 && c == x))
				ft_putchar('\\');
			else if (r > 1 && r < y && c > 1 && c < x)
				ft_putchar(' ');
			else
				ft_putchar('*');
			if (c == x)
				ft_putchar('\n');
			c++;
		}
		r++;
	}
	return ;
}
