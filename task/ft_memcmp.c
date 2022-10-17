/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 16:44:25 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/17 17:21:33 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1ch;
	const unsigned char	*s2ch;
	size_t				pos;

	s1ch = s1;
	s2ch = s2;
	pos = 0;
	while (pos < n)
	{
		if (s1ch[pos] != s2ch[pos])
		{
			return (s1ch[pos] - s2ch[pos]);
		}
		++pos;
	}
	return (0);
}
