/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:18:44 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/21 00:06:25 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_pr(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr_pr(const char *s, int c)
{
	c = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

void	ft_putstr_fd_pr(char *s, int fd)
{
	if (fd > 0 && s != NULL)
		while (*s != '\0')
			if (write(fd, s++, 1) != 1)
				return ;
}

void	ft_putnbr_fd_pr(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd_pr(n / 10, fd);
	ft_putchar_fd_pr('0' + n % 10, fd);
}

void	ft_putchar_fd_pr(char c, int fd)
{
	if (fd > 0)
		write(fd, &c, 1);
}
