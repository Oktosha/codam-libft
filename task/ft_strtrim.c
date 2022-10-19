/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 01:39:43 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/19 02:00:22 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_in_set(char ch, char const *set)
{
	return (ft_strchr(set, ch) != NULL);
}

static char	*freeable_empty_string(void)
{
	char	*ans;

	ans = malloc(sizeof(char));
	if (ans == NULL)
	{
		return (NULL);
	}
	ans[0] = '\0';
	return (ans);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;
	char	*ans;

	len = ft_strlen(s1);
	start = 0;
	while (start < len && is_in_set(s1[start], set))
		++start;
	if (start == len)
		return (freeable_empty_string());
	end = len;
	while (is_in_set(s1[end - 1], set))
		--end;
	ans = malloc(sizeof(char) * (end - start + 1));
	if (ans == NULL)
		return (NULL);
	ft_strlcpy(ans, s1 + start, end - start + 1);
	return (ans);
}
