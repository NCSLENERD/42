/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:46:48 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/08 16:08:54 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

int main(void)
{
	char text1[] = "SALUT A TOUS ET A TOUTES";
	char text2[] = "123BONJOUR123/*}";
	char text3[] = "438475835_))(*&^%##$^&*%";

	printf("%s",ft_strlowcase(text1));
	printf("%s",ft_strlowcase(text2));
	printf("%s",ft_strlowcase(text3));
}
