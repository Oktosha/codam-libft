/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 15:02:59 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/20 15:21:53 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	ssize_t	ret;
	ssize_t	len;
	ssize_t	n_written;

	len = ft_strlen(s);
	ret = write(fd, s, len);
	if (ret == -1)
		n_written = 0;
	else
		n_written = ret;
	while (n_written < len)
	{
		if (ret == -1 && errno != EAGAIN && errno != EWOULDBLOCK
			&& errno != EINTR)
			return ;
		ret = write(fd, s + n_written, len - n_written);
		if (ret != -1)
			n_written += ret;
	}
}
