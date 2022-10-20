/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 01:52:24 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/20 13:53:25 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>

void	ft_putchar_fd(char c, int fd)
{
	ssize_t	ret;

	ret = write(fd, &c, 1);
	while (ret < 1)
	{
		if (ret == 0
			|| errno == EAGAIN || errno == EWOULDBLOCK || errno == EINTR)
		{
			ret = write(fd, &c, 1);
		}
		else
		{
			break ;
		}
	}
}
