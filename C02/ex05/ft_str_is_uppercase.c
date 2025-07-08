/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 20:26:22 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/07 20:35:13 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!('A' <= str[i] && str[i] <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}

/*int main(void)
{
	char *test1 = "AAAAAAAIISAOSOASIUASIASHASHHBSHHSASBVWZBHHZH";
	char *test2 = "AAASSZXDSDEEasaassdsdaZZAA";
	char *test3 = "12456214ASASADSDSDdfdfsdfds}";
	char *test4 = "AAAAAAAAAAASDSDSX}";

	printf("%d",ft_str_is_uppercase(test1));
	printf("%d",ft_str_is_uppercase(test2));
	printf("%d",ft_str_is_uppercase(test3));
	printf("%d",ft_str_is_uppercase(test4));
}*/
