/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 19:35:22 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/21 21:18:08 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	empty_del(void *p)
{
	(void)(p);
}

static t_list	*ft_lstalloc(int len)
{
	t_list	*ans;
	t_list	*prev;
	t_list	*cur;
	int		i;

	if (len <= 0)
		return (NULL);
	ans = ft_lstnew(NULL);
	if (ans == NULL)
		return (NULL);
	prev = ans;
	cur = NULL;
	i = 0;
	while (i++ < len - 1)
	{
		cur = ft_lstnew(NULL);
		if (cur == NULL)
		{
			ft_lstclear(&ans, empty_del);
			return (NULL);
		}
		prev->next = cur;
		prev = cur;
	}
	return (ans);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		len;
	t_list	*ans;
	t_list	*cur_src;
	t_list	*cur_res;

	(void)(del);
	len = ft_lstsize(lst);
	ans = ft_lstalloc(len);
	if (ans == NULL)
		return (NULL);
	cur_src = lst;
	cur_res = ans;
	while (cur_src != NULL)
	{
		cur_res->content = f(cur_src->content);
		cur_res = cur_res->next;
		cur_src = cur_src->next;
	}
	return (ans);
}
