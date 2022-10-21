/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 17:07:58 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/21 23:23:19 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	haystack_len;
	size_t	search_len;
	size_t	pos;

	if (len == 0)
	{
		if (ft_strlen(needle) == 0)
			return ((char *)(haystack));
		return (NULL);
	}
	needle_len = ft_strlen(needle);
	haystack_len = ft_strlen(haystack);
	search_len = ft_min(len, haystack_len);
	pos = 0;
	while (pos + needle_len <= search_len)
	{
		if (ft_strncmp(haystack + pos, needle, needle_len) == 0)
			return ((char *)(haystack + pos));
		++pos;
	}
	return (NULL);
}
