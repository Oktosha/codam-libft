/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:47:11 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/15 17:59:18 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
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

TEST test_ft_isascii(void)
{
	ASSERT(ft_isascii(5));
	ASSERT(ft_isascii(0));
	ASSERT(ft_isascii(127));
	ASSERT_FALSE(ft_isascii(-3));
	ASSERT_FALSE(ft_isascii(128));
	PASS();
}

TEST test_ft_isprint(void)
{
	ASSERT_EQ(isprint(' '), ft_isprint(' '));
	ASSERT_EQ(isprint('~'), ft_isprint('~'));
	ASSERT_EQ(isprint(127), ft_isprint(127));
	ASSERT_EQ(isprint('A'), ft_isprint('A'));
	ASSERT_EQ(isprint(3), ft_isprint(3));
	PASS();
}

TEST test_ft_strlen(void)
{
	ASSERT_EQ(ft_strlen(""), strlen(""));
	ASSERT_EQ(ft_strlen("abcd"), strlen("abcd"));
	PASS();
}

TEST test_ft_memset(void)
{
	char s[] = "abcd";
	ASSERT_EQ(s, ft_memset(s, 'o', 3));
	ASSERT_EQ(strcmp(s, "oood"), 0);
	PASS();
}

TEST test_ft_bzero(void)
{
	char s[] = "abcd";
	ft_bzero(s, 2);
	ASSERT_EQ(s[0], 0);
	ASSERT_EQ(s[1], 0);
	ASSERT_EQ(s[2], 'c');
	PASS();
}

TEST test_ft_memcpy(void)
{
	char dst[] = "efgh";
	char src[] = "abcd";
	ASSERT_EQ(dst, ft_memcpy(dst, src, 2));
	ASSERT_EQ(strcmp(ft_memcpy(dst, src, 2), "abgh"), 0);
	PASS();
}

TEST test_ft_memmove(void)
{
	char s1[] = "abcdef";
	ft_memmove(s1, s1 + 1, 3);
	ASSERT_STR_EQ("bcddef", s1);
	char s2[] = "abcdef";
	ft_memmove(s2 + 1, s2, 3);
	ASSERT_STR_EQ("aabcef", s2);
	char s3[] = "abcdef";
	ft_memmove(s3, s3, 3);
	ASSERT_STR_EQ("abcdef", s3);
	PASS();
}

TEST test_ft_strlcpy(void)
{
	char dst0[] = "abcdefg";
	char dst1[] = "abcdefg";
	char src0[] = "ABC";
	int n0 = ft_strlcpy(dst0, src0, 8);
	int n1 = strlcpy(dst1, src0, 8);
	ASSERT_EQ(0, memcmp(dst0, dst1, 8));
	ASSERT_EQ(n1, n0);
	char dst_short0[] = "abcdefghj";
	char dst_short1[] = "abcdefghj";
	char src1[] = "ABCDEF";
	n0 = ft_strlcpy(dst_short0, src1, 4);
	n1 = strlcpy(dst_short1, src1, 4);
	ASSERT_EQ(n1, n0);
	ASSERT_EQ(0, memcmp(dst_short0, dst_short1, 10));
	char dst_zero0[] = "abcdefg";
	char dst_zero1[] = "abcdefg";
	char src2[]  = "ABC";
	n0 = ft_strlcpy(dst_zero0, src2, 0);
	n1 = strlcpy(dst_zero1, src2, 0);
	ASSERT_EQ(n1, n0);
	ASSERT_EQ(0, memcmp(dst_zero0, dst_zero1, 8));
	PASS();
}

SUITE(part1)
{
	RUN_TEST(test_ft_isalpha);
	RUN_TEST(test_ft_isdigit);
	RUN_TEST(test_ft_isalnum);
	RUN_TEST(test_ft_isascii);
	RUN_TEST(test_ft_isprint);
	RUN_TEST(test_ft_strlen);
	RUN_TEST(test_ft_memset);
	RUN_TEST(test_ft_bzero);
	RUN_TEST(test_ft_memcpy);
	RUN_TEST(test_ft_memmove);
	RUN_TEST(test_ft_strlcpy);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
    GREATEST_MAIN_BEGIN();
	RUN_SUITE(part1);
    GREATEST_MAIN_END();
}