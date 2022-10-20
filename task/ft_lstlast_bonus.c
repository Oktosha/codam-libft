/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 17:33:38 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/20 17:40:05 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ans;

	ans = NULL;
	while (lst != NULL)
	{
		ans = lst;
		lst = lst->next;
	}
	return (ans);
}
