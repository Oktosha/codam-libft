/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 21:23:31 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/15 21:32:08 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	goal;
	unsigned char	*data;
	size_t			pos;

	data = (unsigned char *)(s);
	goal = c;
	pos = 0;
	while (pos < n)
	{
		if (*(data + pos) == goal)
		{
			return (data + pos);
		}
		++pos;
	}
	return (NULL);
}
