/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 15:57:50 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/15 17:18:53 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (srcsize >= dstsize)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[srcsize] = '\0';
	}
	else
	{
		ft_memcpy(dst, src, srcsize + 1);
	}
	return (srcsize);
}
