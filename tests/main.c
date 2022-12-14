/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:47:11 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/21 14:59:11 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <libft.h>
#include <limits.h>
#include <stdio.h>
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
	char src_eq[] = "ABC";
	char dst_eq0[] = "abcdefg";
	char dst_eq1[] = "abcdefg";
	n0 = ft_strlcpy(dst_eq0, src_eq, 4);
	n1 = strlcpy(dst_eq1, src_eq, 4);
	ASSERT_EQ(n1, n0);
	ASSERT_EQ(0, memcmp(dst_eq0, dst_eq1, 8));
	PASS();
}

TEST test_ft_strlcat(void)
{
	char dst_ft[] = "abc\0defgh";
	char dst_gt[] = "abc\0defgh";
	char src[] = "ABC";
	size_t n_gt = strlcat(dst_gt, src, 10);
	size_t n_ft = ft_strlcat(dst_ft, src, 10);
	ASSERT_EQ(n_gt, n_ft);
	ASSERT_EQ(0, memcmp(dst_ft, dst_gt, 10));

	char dst_ft1[] = "abc\0defgh";
	char dst_gt1[] = "abc\0defgh";
	char src1[] = "ABC";
	size_t n_gt1 = strlcat(dst_gt1, src1, 5);
	size_t n_ft1 = ft_strlcat(dst_ft1, src1, 5);
	ASSERT_EQ(n_gt1, n_ft1);
	ASSERT_EQ(0, memcmp(dst_ft1, dst_gt1, 10));

	char dst_ft2[] = "abc\0defgh";
	char dst_gt2[] = "abc\0defgh";
	char src2[] = "ABC";
	size_t n_gt2 = strlcat(dst_gt2, src2, 2);
	size_t n_ft2 = ft_strlcat(dst_ft2, src2, 2);
	ASSERT_EQ(n_gt2, n_ft2);
	ASSERT_EQ(0, memcmp(dst_ft2, dst_gt2, 10));
	PASS();
}

TEST test_ft_toupper(void)
{
	ASSERT_EQ('A', ft_toupper('a'));
	ASSERT_EQ('B', ft_toupper('b'));
	ASSERT_EQ('Z', ft_toupper('z'));
	ASSERT_EQ('A', ft_toupper('A'));
	ASSERT_EQ('B', ft_toupper('B'));
	ASSERT_EQ('Z', ft_toupper('Z'));
	ASSERT_EQ(' ', ft_toupper(' '));
	PASS();
}

TEST test_ft_tolower(void)
{
	ASSERT_EQ('a', ft_tolower('a'));
	ASSERT_EQ('b', ft_tolower('b'));
	ASSERT_EQ('z', ft_tolower('z'));
	ASSERT_EQ('a', ft_tolower('A'));
	ASSERT_EQ('b', ft_tolower('B'));
	ASSERT_EQ('z', ft_tolower('Z'));
	ASSERT_EQ(' ', ft_tolower(' '));
	PASS();
}

TEST test_ft_strchr(void)
{
	const char *s = "abcabc";
	ASSERT_EQ(strchr(s, 'a'), ft_strchr(s, 'a'));
	ASSERT_EQ(strchr(s, 609), ft_strchr(s, 609));
	ASSERT_EQ(strchr(s, 'b'), ft_strchr(s, 'b'));
	ASSERT_EQ(strchr(s, 'd'), ft_strchr(s, 'd'));
	ASSERT_EQ(strchr(s, '\0'), ft_strchr(s, '\0'));
	PASS();
}

TEST test_ft_strrchr(void)
{
	const char *s = "abcbc";
	ASSERT_EQ(strrchr(s, 'a'), ft_strrchr(s, 'a'));
	ASSERT_EQ(strrchr(s, 609), ft_strrchr(s, 609));
	ASSERT_EQ(strrchr(s, 'b'), ft_strrchr(s, 'b'));
	ASSERT_EQ(strrchr(s, 'd'), ft_strrchr(s, 'd'));
	ASSERT_EQ(strrchr(s, '\0'), ft_strrchr(s, '\0'));
	PASS();
}

int sign(int x)
{
	if (x < 0)
	{
		return -1;
	}
	if (x > 0)
	{
		return 1;
	}
	return 0;
}

TEST test_ft_strncmp(void)
{
	ASSERT_EQ(sign(ft_strncmp("abc", "abd", 100)), sign(strncmp("abc", "abd", 100)));
	ASSERT_EQ(sign(ft_strncmp("abc", "abd", 2)), sign(strncmp("abc", "abd", 2)));
	ASSERT_EQ(sign(ft_strncmp("\20012", "", 3)), sign(strncmp("\20012", "", 3)));
	ASSERT_EQ(sign(ft_strncmp("\0a", "\0b", 3)), sign(strncmp("\0a", "\0b", 3)));
	ASSERT_EQ(sign(ft_strncmp("abc", "def", 0)), sign(strncmp("abc", "def", 0)));
	ASSERT_EQ(sign(ft_strncmp("abc", "a", 100)), sign(strncmp("abc", "a", 100)));
	ASSERT_EQ(sign(strncmp("abc", "abc", 100)), sign(ft_strncmp("abc", "abc", 100)));
	PASS();
}

TEST test_ft_memchr(void)
{
	char s[] = "abcd\0efg";
	ASSERT_EQ(ft_memchr(s, '\0', 9), memchr(s, '\0', 9));
	ASSERT_EQ(ft_memchr(s, 'e', 9), memchr(s, 'e', 9));
	ASSERT_EQ(ft_memchr(s, 'f', 3), memchr(s, 'f', 3));
	ASSERT_EQ(ft_memchr(s, 'a', 0), memchr(s, 'a', 0));
	PASS();
}

// https://stackoverflow.com/questions/50433145/bsd-memcmp3-difference-between-manual-and-implementation

TEST test_ft_memcmp(void)
{
	char s1[] = "dbc";
	char s2[] = "abc";
	char s3[] = "adc";
	char s_empty[] = "";
	char s_200[] = "\200";
	ASSERT_EQ(memcmp("abc", "abc", 3), ft_memcmp("abc", "abc", 3));
	ASSERT_EQ(memcmp("dbc", "abc", 0), ft_memcmp("dbc", "abc", 0));
	ASSERT_EQ(memcmp(s1, s2, 3), ft_memcmp(s1, s2, 3));
	ASSERT_EQ(memcmp(s2, s1, 3), ft_memcmp(s2, s1, 3));
	ASSERT_EQ(memcmp(s2, s3, 2), ft_memcmp(s2, s3, 2));
	ASSERT_EQ(memcmp(s_empty, s_200, 1), ft_memcmp(s_empty, s_200, 1));
	ASSERT_EQ(memcmp(s_200, s_empty, 1), ft_memcmp(s_200, s_empty, 1));
	PASS();
}

TEST test_ft_strnstr(void)
{
	char *haystack = "abcdefga";
	char *needle_empty = "";
	char *needle_1 = "a";
	char *needle_2 = "bc";
	char *needle_3 = "efga";
	ASSERT_EQ(strnstr(haystack, needle_empty, 8), ft_strnstr(haystack, needle_empty, 8));
	ASSERT_EQ(strnstr(haystack, needle_empty, 0), ft_strnstr(haystack, needle_empty, 0));
	ASSERT_EQ(strnstr(haystack, needle_1, 0), ft_strnstr(haystack, needle_1, 0));
	ASSERT_EQ(strnstr(haystack, needle_1, 9), ft_strnstr(haystack, needle_1, 9));
	ASSERT_EQ(strnstr(haystack, needle_3, 8), ft_strnstr(haystack, needle_3, 8));
	ASSERT_EQ(strnstr(haystack, needle_3, 100), ft_strnstr(haystack, needle_3, 100));
	ASSERT_EQ(strnstr(haystack, needle_2, 100), ft_strnstr(haystack, needle_2, 100));
	ASSERT_EQ(strnstr(haystack, needle_3, 4), ft_strnstr(haystack, needle_3, 4));
	PASS();
}

TEST test_ft_atoi(void)
{
	ASSERT_EQ(atoi("2147483647"), ft_atoi("2147483647"));
	ASSERT_EQ(atoi("-2147483648"), ft_atoi("-2147483648"));
	ASSERT_EQ(atoi("0"), ft_atoi("0"));
	ASSERT_EQ(atoi("42"), ft_atoi("42"));
	ASSERT_EQ(atoi("1"), ft_atoi("1"));
	ASSERT_EQ(atoi("-1"), ft_atoi("-1"));
	ASSERT_EQ(atoi("-32"), ft_atoi("-32"));
	ASSERT_EQ(atoi("   -32"), ft_atoi("   -32"));
	ASSERT_EQ(atoi("- 32"), ft_atoi("- 32"));
	ASSERT_EQ(atoi("+32"), ft_atoi("+32"));
	ASSERT_EQ(atoi("-32A"), ft_atoi("-32A"));
	PASS();
}

TEST test_ft_calloc(void)
{
	char *s = ft_calloc(4, 1);
	s[0] = 'a';
	s[0] = 'b';
	s[0] = 'c';
	s[0] = '\0';
	free(s);

	int *a = ft_calloc(3, sizeof(int));
	ASSERT_EQ(a[0], 0);
	ASSERT_EQ(a[1], 0);
	ASSERT_EQ(a[2], 0);
	free(a);

	PASS();
}

TEST test_ft_strdup(void)
{
	char *s1 = "abcd";
	char *s2 = ft_strdup(s1);
	ASSERT_STR_EQ(s1, s2);
	free(s2);
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
	RUN_TEST(test_ft_strlcat);
	RUN_TEST(test_ft_toupper);
	RUN_TEST(test_ft_tolower);
	RUN_TEST(test_ft_strchr);
	RUN_TEST(test_ft_strrchr);
	RUN_TEST(test_ft_strncmp);
	RUN_TEST(test_ft_memchr);
	RUN_TEST(test_ft_memcmp);
	RUN_TEST(test_ft_strnstr);
	RUN_TEST(test_ft_atoi);
	RUN_TEST(test_ft_calloc);
	RUN_TEST(test_ft_strdup);
}

TEST test_ft_substr(void)
{
	const char *s = "abcdef";
	char *ss = ft_substr(s, 1, 3);
	ASSERT_STR_EQ("bcd", ss);
	free(ss);
	char *s_end = ft_substr(s, 1, 15);
	ASSERT_STR_EQ("bcdef", s_end);
	free(s_end);
	char *s_zero = ft_substr(s, 1, 0);
	ASSERT_STR_EQ("", s_zero);
	free(s_zero);
	PASS();
}

TEST test_ft_strjoin(void)
{
	char *s = ft_strjoin("abc", "def");
	ASSERT_STR_EQ("abcdef", s);
	free(s);
	s = ft_strjoin("ab", "");
	ASSERT_STR_EQ("ab", s);
	free(s);
	s = ft_strjoin("", "");
	ASSERT_STR_EQ("", s);
	free(s);
	PASS();
}

TEST test_ft_strtrim(void)
{
	char* s = ft_strtrim("", "abcd");
	ASSERT_STR_EQ("", s);
	free(s);
	s = ft_strtrim("", "");
	ASSERT_STR_EQ("", s);
	free(s);
	s = ft_strtrim("abcd", "");
	ASSERT_STR_EQ("abcd", s);
	free(s);
	s = ft_strtrim("a", " ");
	ASSERT_STR_EQ("a", s);
	free(s);
	s = ft_strtrim("   a   a   ", " ");
	ASSERT_STR_EQ("a   a", s);
	free(s);
	s = ft_strtrim("   a   a   ", "a ");
	ASSERT_STR_EQ("", s);
	free(s);
	PASS();
}

TEST test_ft_split(void)
{
	char *s = "abcd";
	char **ans = ft_split(s, ' ');
	ASSERT_STR_EQ("abcd", ans[0]);
	ASSERT_EQ(NULL, ans[1]);
	free(ans[0]);
	free(ans);

	s = "";
	ans = ft_split(s, ' ');
	ASSERT_EQ(NULL, ans[0]);
	free(ans);

	s = "  ab cd   ";
	ans = ft_split(s, ' ');
	ASSERT_STR_EQ("ab", ans[0]);
	ASSERT_STR_EQ("cd", ans[1]);
	ASSERT_EQ(NULL, ans[2]);
	free(ans[0]);
	free(ans[1]);
	free(ans);

	PASS();
}

TEST test_ft_itoa(void)
{
	char *s;
	s = ft_itoa(42);
	ASSERT_STR_EQ("42", s);
	free(s);
	s = ft_itoa(0);
	ASSERT_STR_EQ("0", s);
	free(s);
	s = ft_itoa(1);
	ASSERT_STR_EQ("1", s);
	free(s);
	s = ft_itoa(-1);
	ASSERT_STR_EQ("-1", s);
	free(s);
	s = ft_itoa(-42);
	ASSERT_STR_EQ("-42", s);
	free(s);
	s = ft_itoa(1000);
	ASSERT_STR_EQ("1000", s);
	free(s);
	s = ft_itoa(-1000);
	ASSERT_STR_EQ("-1000", s);
	free(s);
	s = ft_itoa(INT_MAX);
	ASSERT_STR_EQ("2147483647", s);
	free(s);
	s = ft_itoa(INT_MIN);
	ASSERT_STR_EQ("-2147483648", s);
	free(s);
	PASS();
}

char my_weird_f(unsigned int pos, char ch)
{
	return ch + pos;
}

char my_upper_f(unsigned int pos, char ch)
{
	(void)(pos);
	return toupper(ch);
}

TEST test_ft_strmapi(void)
{
	char *s;
	s = ft_strmapi("000", my_weird_f);
	ASSERT_STR_EQ("012", s);
	free(s);
	s = ft_strmapi("aBc", my_upper_f);
	ASSERT_STR_EQ("ABC", s);
	free(s);
	s = ft_strmapi("", my_weird_f);
	ASSERT_STR_EQ("", s);
	free(s);
	PASS();
}

void my_writing_upper(unsigned int pos, char *c)
{
	(void)(pos);
	*c = toupper(*c);
}

TEST test_ft_striteri(void)
{
	char s[] = "abcd";
	ft_striteri(s, my_writing_upper);
	ASSERT_STR_EQ("ABCD", s);
	PASS();
}

TEST test_ft_putchar_fd(void)
{
	FILE *file = tmpfile();
	ft_putchar_fd('c', fileno(file));
	ft_putchar_fd('d', fileno(file));
	rewind(file);
	ASSERT_EQ('c', fgetc(file));
	ASSERT_EQ('d', fgetc(file));
	ASSERT_EQ(EOF, fgetc(file));
	fclose(file);
	PASS();
}

TEST test_ft_putstr_fd(void)
{
	FILE *file = tmpfile();
	ft_putstr_fd("cd", fileno(file));
	rewind(file);
	ASSERT_EQ('c', fgetc(file));
	ASSERT_EQ('d', fgetc(file));
	ASSERT_EQ(EOF, fgetc(file));
	fclose(file);
	PASS();
}

TEST test_ft_putendl_fd(void)
{
	FILE *file = tmpfile();
	ft_putendl_fd("cd", fileno(file));
	rewind(file);
	ASSERT_EQ('c', fgetc(file));
	ASSERT_EQ('d', fgetc(file));
	ASSERT_EQ('\n', fgetc(file));
	ASSERT_EQ(EOF, fgetc(file));
	fclose(file);
	PASS();
}

static enum greatest_test_res test_one_ft_putnbr(int nbr)
{
	FILE *file = tmpfile();
	ft_putnbr_fd(nbr, fileno(file));
	rewind(file);
	char s[100];
	sprintf(s, "%d", nbr);
	for (size_t i = 0; i < strlen(s); ++i)
	{
		ASSERT_EQ(s[i], fgetc(file));
	}
	ASSERT_EQ(EOF, fgetc(file));
	fclose(file);
	PASS();
}

TEST test_ft_putnbr_fd(void)
{
	CHECK_CALL(test_one_ft_putnbr(1));
	CHECK_CALL(test_one_ft_putnbr(0));
	CHECK_CALL(test_one_ft_putnbr(5));
	CHECK_CALL(test_one_ft_putnbr(-1));
	CHECK_CALL(test_one_ft_putnbr(-5));
	CHECK_CALL(test_one_ft_putnbr(10));
	CHECK_CALL(test_one_ft_putnbr(-10));
	CHECK_CALL(test_one_ft_putnbr(-9));
	CHECK_CALL(test_one_ft_putnbr(9));
	CHECK_CALL(test_one_ft_putnbr(INT_MAX));
	CHECK_CALL(test_one_ft_putnbr(INT_MIN));
	CHECK_CALL(test_one_ft_putnbr(42));
	CHECK_CALL(test_one_ft_putnbr(-42));
	CHECK_CALL(test_one_ft_putnbr(10000));
	CHECK_CALL(test_one_ft_putnbr(-10000));
	CHECK_CALL(test_one_ft_putnbr(1283503));
	CHECK_CALL(test_one_ft_putnbr(-1283503));
	CHECK_CALL(test_one_ft_putnbr(-99));
	CHECK_CALL(test_one_ft_putnbr(99));
	PASS();
}

SUITE(part2)
{
	RUN_TEST(test_ft_substr);
	RUN_TEST(test_ft_strjoin);
	RUN_TEST(test_ft_strtrim);
	RUN_TEST(test_ft_split);
	RUN_TEST(test_ft_itoa);
	RUN_TEST(test_ft_strmapi);
	RUN_TEST(test_ft_striteri);
	RUN_TEST(test_ft_putchar_fd);
	RUN_TEST(test_ft_putstr_fd);
	RUN_TEST(test_ft_putendl_fd);
	RUN_TEST(test_ft_putnbr_fd);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
    GREATEST_MAIN_BEGIN();
	RUN_SUITE(part1);
	RUN_SUITE(part2);
	system("leaks test");
    GREATEST_MAIN_END();
}
