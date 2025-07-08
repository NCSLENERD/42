/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 20:52:20 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/08 14:32:50 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}
/*int main(void)
{
	char *test1 = "  /  ";
        char *test2 = "abc";
        char test3[] = "dasdadaSASKASAHJDHDADADBADBAD";
        char test4[] = "yo";
	
        printf("%s",ft_strupcase(test1));
        printf("%s",ft_strupcase(test2));
        printf("%s",ft_strupcase(test3));
        printf("%s",ft_strupcase(test4));

}*/
