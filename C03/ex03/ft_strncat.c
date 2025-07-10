/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:46:32 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/10 16:23:45 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (dest[j] != '\0')
	{
		j++;
	}
	i = 0 ;
	while (src[i] != '\0' && i < nb)
	{
		dest[i + j] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (dest);
}
/*#include<string.h>
 * #include<stdio.h>
int main (void)
{
	char text1[] = "bonjour";
	char text2[20] = "salut";

	printf("%s",ft_strncat(text2,text1,4));
	//printf("%s",strncat(text2,text1,4));
}*/
