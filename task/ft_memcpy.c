/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 18:58:37 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/13 19:06:46 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_as_str;
	const char	*src_as_str;
	size_t		pos;

	dst_as_str = dst;
	src_as_str = src;
	pos = 0;
	while (pos < n)
	{
		dst_as_str[pos] = src_as_str[pos];
		++pos;
	}
	return (dst);
}
