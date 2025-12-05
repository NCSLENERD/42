/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:19:34 by nmayela           #+#    #+#             */
/*   Updated: 2025/11/25 20:19:36 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*res;
	unsigned char	*src_stock;
	size_t			i;

	res = (unsigned char *)dest;
	src_stock = (unsigned char *)src;
	if (res == src_stock || n == 0)
		return (dest);
	i = 0;
	if (res < src_stock)
	{
		while (i < n)
		{
			res[i] = src_stock[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
		{
			res[n] = src_stock[n];
		}
	}
	return (dest);
}
/*int main()
{
    char buffer[10] = "ABCDEFG";
    ft_memmove(buffer+2, buffer, 0);
    printf("%s\n", buffer);  // Affiche : ABABCDE

    return 0;

}*/