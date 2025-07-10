/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:27:20 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/10 19:15:33 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
//verifier si on met unsigned char ou juste char
void	ft_convert(char *str)
{
	char	*base;

	base = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &base[*str / 16], 1);
	*str = base[*str % 16];
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			ft_convert(&str[i]);
		}
		write(1, &str[i], 1);
		i++;
	}
}
/*int main(void)
{
	char text[]= "Hello\nHow are you?";
	char tab[1];
	tab[0] = -1;
	ft_putstr_non_printable(text);
}*/
