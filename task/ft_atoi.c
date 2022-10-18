/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 20:31:58 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/18 23:41:33 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

static int	ft_clamp(long long int x)
{
	if (x < INT_MIN)
	{
		return (INT_MIN);
	}
	if (x > INT_MAX)
	{
		return (INT_MAX);
	}
	return (x);
}

int	ft_atoi(const char *str)
{
	long long int	n;
	long long int	sign;
	long long int	upperlimit;
	int				pos;

	n = 0;
	sign = 1;
	upperlimit = (long long)(INT_MAX) + (long long)(1);
	pos = 0;
	while (ft_isspace(str[pos]))
		++pos;
	if (str[pos] == '-')
		sign = -1;
	if (str[pos] == '+' || str[pos] == '-')
		++pos;
	while (ft_isdigit(str[pos]) && n < upperlimit)
	{
		n *= 10;
		n += str[pos] - '0';
		++pos;
	}
	return (ft_clamp(n * sign));
}
