/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 14:54:13 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/19 15:03:08 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ans;
	size_t			len;
	unsigned int	pos;

	len = ft_strlen(s);
	ans = malloc(sizeof(char) * (len + 1));
	if (ans == NULL)
		return (NULL);
	pos = 0;
	while (pos < len)
	{
		ans[pos] = f(pos, s[pos]);
		++pos;
	}
	ans[len] = '\0';
	return (ans);
}
