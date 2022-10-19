/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 14:13:41 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/19 14:45:02 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_len(long long x)
{
	int	ans;

	if (x == 0)
	{
		return (1);
	}
	ans = 0;
	while (x > 0)
	{
		ans++;
		x /= 10;
	}
	return (ans);
}

static long long	ft_abs(long long x)
{
	if (x < 0)
	{
		return (-x);
	}
	return (x);
}

static void	reverse_str(char *s)
{
	size_t	len;
	size_t	i;
	char	tmp;

	len = ft_strlen(s);
	i = 0;
	while (i < len / 2)
	{
		tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
		++i;
	}
}

char	*ft_itoa(int n)
{
	int			len;
	int			i;
	char		*ans;
	long long	abs_n;

	abs_n = ft_abs(n);
	len = count_len(abs_n);
	ans = malloc(sizeof(char) * (len + 1 + (n < 0)));
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ans[i++] = (abs_n % 10) + '0';
		abs_n /= 10;
	}
	if (n < 0)
		ans[i++] = '-';
	ans[i] = '\0';
	reverse_str(ans);
	return (ans);
}
