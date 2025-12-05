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

size_t	ft_strlcat(char *dest, const char *src, size_t s)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	i = 0;
	while (dest[i])
		i++;
	dest_len = i;
	if (s == 0)
		return (src_len);
	else if (s <= dest_len)
		return (src_len + s);
	j = 0;
	while (src[j] && i < s - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}
/*int main (void)
{
	int	i = 0;
	char tab[5] = "Yo "; 
	char tab2[5] = "Yo ";
	ft_strlcat
	printf("ft_strlcat\n");
	printf("Le faux : ft_strlcat %ld\n",ft_strlcat(tab2,"bonjour",2));
	i = 0;
	while(tab2[i])
	{
		printf("%c",tab2[i]);
		i++;
	}
	printf("\n");
	i = 0;
	printf("Le vrai : strlcat %ld\n",strlcat(tab,"bonjour",2));
	while(tab[i])
	{
		printf("%c",tab[i]);
		i++;
	}
	printf("\n");
	printf("\n");


}*/
