/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 17:55:42 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/20 18:03:32 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	**p;

	if (lst == NULL)
		return ;
	p = lst;
	while (*p != NULL)
		p = &((*p)->next);
	*p = new;
}
