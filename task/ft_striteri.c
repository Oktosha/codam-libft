/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 01:36:12 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/20 01:42:27 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t			len;
	unsigned int	pos;

	len = ft_strlen(s);
	pos = 0;
	while (pos < len)
	{
		f(pos, s + pos);
		++pos;
	}
}
