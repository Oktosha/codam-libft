/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 20:28:59 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/15 21:12:06 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	ch;

	ch = c;
	p = (char *)(s + ft_strlen(s));
	while (p != s && *p != ch)
	{
		--p;
	}
	if (*p == ch)
		return (p);
	return (NULL);
}
