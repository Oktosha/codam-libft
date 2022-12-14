/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 17:48:49 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/20 20:11:02 by dkolodze      ########   odam.nl         */
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

TEST test_ft_lstlast(void)
{
	ASSERT_EQ(NULL, ft_lstlast(NULL));
	char ch = 'X';
	t_list *node1 = ft_lstnew(&ch);
	ASSERT_EQ(node1, ft_lstlast(node1));
	t_list *node2 = ft_lstnew(&ch);
	node1->next = node2;
	ASSERT_EQ(node2, ft_lstlast(node1));
	t_list *node3 = ft_lstnew(&ch);
	node2->next = node3;
	ASSERT_EQ(node3, ft_lstlast(node1));
	free(node1);
	free(node2);
	free(node3);
	PASS();
}

TEST test_ft_lstadd_back(void)
{
	char *s = "abc";
	t_list *nodes[] = {ft_lstnew(s), ft_lstnew(s + 1), ft_lstnew(s + 2)};
	t_list *p = NULL;
	ft_lstadd_back(NULL, nodes[0]);
	ft_lstadd_back(&p, nodes[0]);
	ASSERT_EQ(p, nodes[0]);
	ft_lstadd_back(&p, nodes[1]);
	ASSERT_EQ(p->next, nodes[1]);
	ft_lstadd_back(&p, nodes[2]);
	ASSERT_EQ(p->next->next, nodes[2]);
	for (int i = 0; i < 3; ++i)
		free(nodes[i]);
	PASS();
}

void strdel(void *s)
{
	free(s);
}

TEST test_ft_lstdelone(void)
{
	char *s = "abc";
	char *smem = strdup(s);
	t_list *node = ft_lstnew(smem);
	ft_lstdelone(node, strdel);
	PASS();
}

void nothingdel(void *s)
{
	(void)(s);
}

TEST test_ft_lstclear(void)
{
	char *s = "abc";
	t_list *nodes[] = {ft_lstnew(s), ft_lstnew(s + 1), ft_lstnew(s + 2)};
	nodes[0]->next = nodes[1];
	nodes[1]->next = nodes[2];
	ft_lstclear(nodes, nothingdel);
	ASSERT_EQ(NULL, nodes[0]);
	PASS();
}

void changetoupper(void *p)
{
	char *pch = p;
	*pch = toupper(*pch);
}

TEST test_ft_lstiter(void)
{
	char s[] = "abc";
	t_list *nodes[] = {ft_lstnew(s), ft_lstnew(s + 1), ft_lstnew(s + 2)};
	nodes[0]->next = nodes[1];
	nodes[1]->next = nodes[2];
	ft_lstiter(nodes[0], changetoupper);
	ASSERT_STR_EQ("ABC", s);
	ft_lstclear(nodes, nothingdel);
	PASS();
}

void *allocate_upper(void *p)
{
	char *ans = malloc(sizeof(char) * 1);
	if (ans == NULL)
	{
		return (NULL);
	}
	*ans = toupper(*((char *)(p)));
	return ans;
}

TEST test_ft_lstmap(void)
{
	char *s = "abc";
	t_list *nodes[] = {ft_lstnew(s), ft_lstnew(s + 1), ft_lstnew(s + 2)};
	nodes[0]->next = nodes[1];
	nodes[1]->next = nodes[2];
	t_list *lst = ft_lstmap(nodes[0], allocate_upper, strdel);
	ASSERT_EQ(*((char *)(lst->content)), 'A');
	ASSERT_EQ(*((char *)(lst->next->content)), 'B');
	ASSERT_EQ(*((char *)(lst->next->next->content)), 'C');
	ASSERT_EQ(lst->next->next->next, NULL);
	ft_lstclear(&lst, strdel);
	ft_lstclear(nodes, nothingdel);
	PASS();
}

SUITE(bonus)
{
	RUN_TEST(test_ft_lstnew);
	RUN_TEST(test_ft_lstadd_front);
	RUN_TEST(test_ft_lstsize);
	RUN_TEST(test_ft_lstlast);
	RUN_TEST(test_ft_lstadd_back);
	RUN_TEST(test_ft_lstdelone);
	RUN_TEST(test_ft_lstclear);
	RUN_TEST(test_ft_lstiter);
	RUN_TEST(test_ft_lstmap);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
    GREATEST_MAIN_BEGIN();
	RUN_SUITE(bonus);
	system("leaks test-bonus");
    GREATEST_MAIN_END();
}
