/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:47:11 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/11 14:20:38 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "greatest.h"

TEST test_ft_isalpha(void)
{
	ASSERT(ft_isalpha('a'));
	ASSERT(ft_isalpha('A'));
	ASSERT(ft_isalpha('z'));
	ASSERT(ft_isalpha('Z'));
	ASSERT(ft_isalpha('b'));
	ASSERT(ft_isalpha('B'));
	ASSERT_FALSE(ft_isalpha('0'));
	ASSERT_FALSE(ft_isalpha('\n'));
	ASSERT_FALSE(ft_isalpha(' '));
	PASS();
}

TEST test_ft_isdigit(void)
{
	ASSERT(ft_isdigit('0'));
	ASSERT(ft_isdigit('5'));
	ASSERT(ft_isdigit('9'));
	ASSERT_FALSE(ft_isdigit('a'));
	ASSERT_FALSE(ft_isdigit('\n'));
	PASS();
}

TEST test_ft_isalnum(void)
{
	ASSERT(ft_isalnum('A'));
	ASSERT_FALSE(ft_isalnum('!'));
	PASS();
}

SUITE(part1)
{
	RUN_TEST(test_ft_isalpha);
	RUN_TEST(test_ft_isdigit);
	RUN_TEST(test_ft_isalnum);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
    GREATEST_MAIN_BEGIN();
	RUN_SUITE(part1);
    GREATEST_MAIN_END();
}