/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 01:25:41 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/19 01:31:55 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ans;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ans = malloc(sizeof(char) * (len1 + len2 + 1));
	if (ans == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(ans, s1, len1 + 1);
	ft_strlcpy(ans + len1, s2, len2 + 1);
	return (ans);
}
