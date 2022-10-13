/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 16:35:16 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/13 19:48:19 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_as_string;
	unsigned char	c_as_uchar;
	size_t			pos;

	b_as_string = b;
	c_as_uchar = c;
	pos = 0;
	while (pos < len)
	{
		b_as_string[pos] = c_as_uchar;
		++pos;
	}
	return (b);
}
