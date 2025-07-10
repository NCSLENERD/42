/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:40:03 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/10 17:11:25 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && i <= n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
/*#include<stdio.h>
#include<string.h>
int main(void)
{
	char text1[] = "salut!";
	char text2[] ="salut";
	
	printf("%d",ft_strncmp(text1,text2,6));
	printf("%d",strncmp(text1,text2,6));
}*/
