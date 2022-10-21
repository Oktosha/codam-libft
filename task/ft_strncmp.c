/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 20:46:09 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/21 15:01:05 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	pos;

	if (n == 0)
	{
		return (0);
	}
	pos = 0;
	while (pos < n - 1 && *(s1 + pos) == *(s2 + pos) && *(s1 + pos) != '\0')
	{
		++pos;
	}
	return ((unsigned char)(*(s1 + pos)) - (unsigned char)(*(s2 + pos)));
}
