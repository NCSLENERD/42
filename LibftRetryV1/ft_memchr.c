/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:01:24 by nmayela           #+#    #+#             */
/*   Updated: 2025/11/26 18:01:26 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*buffer;

	i = 0;
	buffer = (unsigned char *)s;
	while (i < n)
	{
		if (*buffer == (unsigned char)c)
			return (buffer);
		buffer++;
		i++;
	}
	return (NULL);
}
/*int main()
{
	char text[10] = "Bonjour";
	printf("%s",ft_memchr(text,'j',10));

}*/