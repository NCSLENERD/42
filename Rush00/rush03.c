/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:12:53 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/06 17:21:07 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	r;
	int	c;

	r = 1;
	while (!(x <= 0) && !(y <= 0) && (r <= y))
	{
		c = 1;
		while (c <= x)
		{
			if ((r == 1 && c == 1) || (r == y && c == 1))
				ft_putchar('A');
			else if ((r == 1 && c == x) || (r == y && c == x))
				ft_putchar('C');
			else if (r > 1 && r < y && c > 1 && c < x)
				ft_putchar(' ');
			else
				ft_putchar('B');
			c++;
		}
		ft_putchar('\n');
		r++;
	}
	return ;
}
