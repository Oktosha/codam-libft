/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 17:24:09 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/20 17:24:37 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	ans;

	ans = 0;
	while (lst != NULL)
	{
		++ans;
		lst = lst->next;
	}
	return (ans);
}
