/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 15:36:28 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/20 15:49:44 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0 && n <= 9)
	{
		ft_putchar_fd('0' + n, fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if ((-(long long)(n)) > 9)
			ft_putnbr_fd(-(n / 10), fd);
		ft_putchar_fd((-(long long)(n)) % 10 + '0', fd);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}
