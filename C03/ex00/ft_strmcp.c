/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmcp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:15:54 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/10 17:40:52 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/*#include <stdio.h>
#include<string.h>
int main(void)
{
	char text1[] = "bonjouryo";
	char text2[] = "bonjouryo";

	printf("%d",ft_strcmp(text1,text2));
	printf("\n");
	printf("%d",strcmp(text1,text2));
}*/
