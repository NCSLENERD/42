/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:05:24 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/10 14:10:54 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	taille;

	taille = 0;
	while (dest[taille] != '\0')
	{
		taille++;
	}
	i = 0;
	while (src[i] != '\0')
	{
		dest[taille + i] = src[i];
		i++;
	}
	dest[taille + i] = '\0';
	return (dest);
}
/*#include <stdio.h>
int main (void)
{
	char text1[] = "salut";
	char text2[40];
	text2[0] = 'b';
	text2[1] = 'j';
	text2[2] = 'r';

	printf("%s",ft_strcat(text2,text1));
	//printf("%s",text2);
	//ft_strcat(text2,text1);
	//printf("%s",text2);
}*/
