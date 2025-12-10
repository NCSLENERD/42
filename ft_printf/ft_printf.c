/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:33:45 by nmayela           #+#    #+#             */
/*   Updated: 2025/12/09 14:33:47 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

static void	printf_parse(char format, va_list *current, int *ptr)
{
	if (format == 's')
		ft_putstr_fd_mod(va_arg(*current, char *), 1, ptr);
	else if (format == 'c')
		ft_putchar_fd(va_arg(*current, int), 1, ptr);
	else if (format == 'd' || format == 'i')
		ft_putnbr_fd(va_arg(*current, int), 1, ptr);
	else if (format == 'u')
		ft_putnbr_unsigned(va_arg(*current, unsigned int), ptr);
	else if (format == 'x')
		ft_putnbr_base(va_arg(*current, unsigned int), "0123456789abcdef", ptr);
	else if (format == 'X')
		ft_putnbr_base(va_arg(*current, unsigned int), "0123456789ABCDEF", ptr);
	else if (format == '%')
		ft_putchar_fd(format, 1, ptr);
	else if (format == 'p')
	{
		ft_putnbr_base_ptr(va_arg(*current, void *), "0123456789abcdef", ptr);
	}
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		*ptr;
	int		res;
	va_list	current;

	va_start(current, format);
	i = 0;
	res = 0;
	ptr = &res;
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar_fd(format[i], 1, ptr);
		if (format[i] == '%')
		{
			i++;
			printf_parse(format[i], &current, ptr);
		}
		i++;
	}
	va_end(current);
	return (*ptr);
}
/*int main(void)
{
	char* prenom = NULL;
	//char *ptr = "Nicolas";
	ft_printf("%p",prenom);
	printf("\n");
	//printf("%s",prenom);
	printf("\n");
}*/
