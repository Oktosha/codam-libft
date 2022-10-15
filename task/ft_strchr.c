/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 20:18:17 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/15 20:27:06 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char	*ans;

	ans = (char *)(s);
	while (*ans != c && *ans != '\0')
	{
		++ans;
	}
	if (*ans == c)
	{
		return (ans);
	}
	return (NULL);
}
