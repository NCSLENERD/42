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

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *) s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *) s);
	return (NULL);
}
/*int main (void)
{
	printf("%p\n",strchr("teste",'e'));
	printf("%p\n",ft_strchr("teste",'t'));
}*/
