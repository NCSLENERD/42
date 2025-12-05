/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 23:40:20 by nmayela           #+#    #+#             */
/*   Updated: 2025/11/24 23:40:23 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*result;
	size_t			i;

	i = 0;
	result = (unsigned char *)s;
	while (i < n)
	{
		result[i] = '\0';
		i++;
	}
}
/*int main()
{
    char text[10] = "0123456789";
    printf("Avant : %s\n",text);
    ft_bzero(text,10);
    printf("Apres : %s\n",text);

}*/