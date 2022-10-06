/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 17:49:23 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/03 19:07:47 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	ft_islower(int c)
{
	return ((c <= 'z') && (c >= 'a'));
}

static int	ft_isupper(int c)
{
	return ((c <= 'Z') && (c >= 'A'));
}

int	ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}
