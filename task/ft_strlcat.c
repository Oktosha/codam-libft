/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 17:43:28 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/15 20:43:49 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	srclen = ft_strlen(src);
	dstlen = 0;
	while (dstlen < dstsize && dst[dstlen] != '\0')
	{
		++dstlen;
	}
	i = 0;
	while (i + dstlen + 1 < dstsize && i < srclen)
	{
		dst[i + dstlen] = src[i];
		++i;
	}
	if (i + dstlen < dstsize)
		dst[i + dstlen] = '\0';
	return (srclen + dstlen);
}
