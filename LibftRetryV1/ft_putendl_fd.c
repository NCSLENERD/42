/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:14:43 by nmayela           #+#    #+#             */
/*   Updated: 2025/11/30 14:14:44 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>

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

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write (fd, s, len);
	write(fd, "\n", 1);
}
/*int main (void)
{
	int fd_test = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	char *s = "AND I WILL BE RICH ONE DAY !";

	ft_putendl_fd(s,fd_test);
	close(fd_test);
}*/