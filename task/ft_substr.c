/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 01:02:23 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/20 22:36:59 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;

	if (ft_strlen(s) <= start)
	{
		ans = malloc(sizeof(char) * 1);
		if (ans == NULL)
			return (NULL);
		ans[0] = '\0';
		return (ans);
	}
	len = ft_min(ft_strlen(s + start), len);
	ans = malloc(sizeof(char) * (len + 1));
	if (ans == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(ans, s + start, len + 1);
	return (ans);
}
