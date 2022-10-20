/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 18:38:47 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/20 18:43:33 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;
	t_list	*next;

	if (lst == NULL)
		return ;
	p = *lst;
	while (p != NULL)
	{
		next = p->next;
		ft_lstdelone(p, del);
		p = next;
	}
	*lst = NULL;
}
