/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 22:24:20 by nmayela           #+#    #+#             */
/*   Updated: 2025/12/09 22:24:23 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

void	ft_putnbr_base_ptr(void *n, char *base, int *res);
void	ft_putnbr_unsigned(unsigned int n, int *res);
void	ft_putnbr_base(int n, char *base, int *res);
void	ft_putstr_fd_mod(char *s, int fd, int *res);
void	ft_putnbr_fd(int n, int fd, int *res);
void	ft_putchar_fd(char c, int fd, int *res);
int		ft_printf(const char *format, ...);

#endif
