/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:28:35 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/11 14:29:48 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return ((c >= 0) && (c <= 0177));
}
