/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 20:18:17 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/15 21:11:34 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char	*ans;
	char	ch;

	ans = (char *)(s);
	ch = c;
	while (*ans != ch && *ans != '\0')
	{
		++ans;
	}
	if (*ans == ch)
	{
		return (ans);
	}
	return (NULL);
}
