/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_mod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 22:40:01 by nmayela           #+#    #+#             */
/*   Updated: 2025/12/09 22:40:02 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd_mod(char *s, int fd, int *res)
{
	size_t	len;

	if (!s)
	{
		ft_putstr_fd_mod("(null)", fd, res);
		return ;
	}
	len = ft_strlen(s);
	*res = len + *res;
	write (fd, s, len);
}
/*int main(void)
{
	int *res;
	int rr;
	rr = 0;
	res = &rr;
	ft_putstr_fd_mod(NULL, 1, res);
	ft_putnbr_fd(rr,1,res);
}*/
