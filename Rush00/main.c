/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:02:30 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/06 16:57:24 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y);

int	main(void)
{
	rush(5, 3);
	ft_putchar('\n');
	rush(5, 1);
	ft_putchar('\n');
	rush(1, 1);
	ft_putchar('\n');
	rush(1, 5);
	ft_putchar('\n');
	rush(4, 4);
	ft_putchar('\n');
	rush(0, 0);
	ft_putchar('\n');
	rush(0, -1);
	ft_putchar('\n');
	rush(-1, 0);
	ft_putchar('\n');
	rush(-1, -1);
	ft_putchar('\n');
	rush(10, 5);
	ft_putchar('\n');
	return (0);
}
