/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 00:07:55 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/19 00:25:30 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	size_t			pos;

	p = malloc(count * size);
	if (p == NULL)
	{
		return (NULL);
	}
	pos = 0;
	while (pos < count * size)
	{
		p[pos] = 0;
		++pos;
	}
	return (p);
}
