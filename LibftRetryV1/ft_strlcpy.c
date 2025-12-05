/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 00:14:46 by nmayela           #+#    #+#             */
/*   Updated: 2025/11/11 00:14:48 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t s)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (s == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < s - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
/*int main (void)
{
	int	i = 0;
	char tab[5] = "Yo "; 
	char tab2[5] = "Yo ";

    ft_strlcpy
	printf("ft_strlcpy\n");
	printf("test le vrai strlcpy %ld\n",strlcpy(tab,"bonjour",0));
	while(tab[i])
	{
		printf("%c",tab[i]);
		i++;
	}
	printf("\n");
	printf("\n");
	printf("ft_strlcpy\n");
	printf("test le faux ft_strlcpy %ld\n",ft_strlcpy(tab2,"bonjour",0));
	i = 0;
	while(tab2[i])
	{
		printf("%c",tab2[i]);
		i++;
	}
	printf("\n");
	printf("\n");
}*/
