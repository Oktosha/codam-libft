/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 17:48:49 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/10 18:01:56 by dkolodze      ########   odam.nl         */
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
	PASS();
}

SUITE(bonus)
{
	RUN_TEST(test_ft_lstnew);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
    GREATEST_MAIN_BEGIN();
	RUN_SUITE(bonus);
    GREATEST_MAIN_END();
}