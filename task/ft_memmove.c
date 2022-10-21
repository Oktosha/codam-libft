/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 19:26:28 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/21 20:29:00 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		pos;
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (d < s)
	{
		pos = 0;
		while (pos < len)
		{
			d[pos] = s[pos];
			++pos;
		}
	}
	else if (d > s)
	{
		pos = len;
		while (pos-- > 0)
		{
			d[pos] = s[pos];
		}
	}
	return (dst);
}
