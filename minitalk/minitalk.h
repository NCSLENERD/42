/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:22:48 by nmayela           #+#    #+#             */
/*   Updated: 2026/04/12 15:22:49 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_putnbr_base_ptr(void *n, char *base, int *res);
void	ft_putnbr_unsigned(unsigned int n, int *res);
void	ft_putnbr_base(int n, char *base, int *res);
void	ft_putstr_fd_mod(char *s, int fd, int *res);
void	ft_putnbr_fd(int n, int fd, int *res);
void	ft_putchar_fd(char c, int fd, int *res);
int		ft_printf(const char *format, ...);
int		ft_atoi(const char *nptr);

#endif
