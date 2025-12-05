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

char	*ft_strrchr(const char *s, int c)
{
	char		*result;
	int			flag;

	flag = 0;
	result = NULL;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
		{
			result = (char *)s;
			flag = 1;
		}
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *) s);
	else if (flag == 1)
		return ((char *) result);
	return (NULL);
}
/*int main (void)
{
	ft_strrchr
	printf("%s\n",strrchr("bonjour",'o'));
	printf("%s\n",ft_strrchr("bonjour",'o'));
}*/
