/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:26:39 by nmayela           #+#    #+#             */
/*   Updated: 2025/11/26 18:26:40 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_stock;
	unsigned char	*s2_stock;

	i = 0;
	s1_stock = (unsigned char *)s1;
	s2_stock = (unsigned char *)s2;
	while (i < n)
	{
		if (s1_stock[i] != s2_stock[i])
			return (s1_stock[i] - s2_stock[i]);
		i++;
	}
	return (0);
}
/*int main()
{
	char text[10] = "Bonjoupp";
	char text2[10] = "Bonjourpp";
	printf("%d\n",ft_memcmp(text,text2,10));
}*/