/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 17:48:49 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/20 17:29:13 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "greatest.h"

TEST test_ft_lstnew(void)
{
	char ch = 'a';
	t_list *node = ft_lstnew(&ch);
	ASSERT_EQ(node->next, NULL);
	ASSERT_EQ(*((char *)(node->content)), 'a');
	free(node);
	PASS();
}

TEST test_ft_lstadd_front(void)
{
	char ch1 = 'a';
	char ch2 = 'b';
	t_list *node = ft_lstnew(&ch1);
	t_list *new_node = ft_lstnew(&ch2);
	ft_lstadd_front(&node, new_node);
	ASSERT_EQ(node, new_node);
	ASSERT_EQ(node->content, &ch2);
	ASSERT_EQ(node->next->content, &ch1);
	ASSERT_EQ(node->next->next, NULL);
	free(node->next);
	free(node);
	PASS();
}

TEST test_ft_lstsize(void)
{
	ASSERT_EQ(0, ft_lstsize(NULL));
	char ch = 'X';
	t_list *node1 = ft_lstnew(&ch);
	ASSERT_EQ(1, ft_lstsize(node1));
	t_list *node2 = ft_lstnew(&ch);
	node1->next = node2;
	ASSERT_EQ(2, ft_lstsize(node1));
	t_list *node3 = ft_lstnew(&ch);
	node2->next = node3;
	ASSERT_EQ(3, ft_lstsize(node1));
	free(node1);
	free(node2);
	free(node3);
	PASS();
}

SUITE(bonus)
{
	RUN_TEST(test_ft_lstnew);
	RUN_TEST(test_ft_lstadd_front);
	RUN_TEST(test_ft_lstsize);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
    GREATEST_MAIN_BEGIN();
	RUN_SUITE(bonus);
    GREATEST_MAIN_END();
}
