/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 02:03:15 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/10/19 02:37:47 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		ans;
	size_t	pos;
	size_t	len;

	ans = 0;
	pos = 0;
	len = ft_strlen(s);
	while (pos < len)
	{
		if (s[pos] != c && (pos == 0 || s[pos - 1] == c))
			++ans;
		++pos;
	}
	return (ans);
}

// copies n characters from s than adds '\0'
static char	*ft_dummy_strndup(char const *s, size_t n)
{
	char	*ans;

	ans = malloc(sizeof(char) * (n + 1));
	if (ans == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(ans, s, n + 1);
	return (ans);
}

static void	free_array(char **a, int n)
{
	int	pos;

	pos = 0;
	while (pos < n)
	{
		free(a[pos]);
		++pos;
	}
	free(a);
}

static size_t	get_word_len(char const *s, char c)
{
	size_t	ans;

	ans = 0;
	while (s[ans] != '\0' && s[ans] != c)
	{
		++ans;
	}
	return (ans);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		n_words;
	int		i_word;

	n_words = count_words(s, c);
	ans = malloc(sizeof(char *) * (n_words + 1));
	if (ans == NULL)
		return (NULL);
	i_word = 0;
	while (i_word < n_words)
	{
		while (*s == c)
			++s;
		ans[i_word] = ft_dummy_strndup(s, get_word_len(s, c));
		if (ans[i_word] == NULL)
		{
			free_array(ans, i_word);
			return (NULL);
		}
		++i_word;
		s += get_word_len(s, c);
	}
	ans[n_words] = NULL;
	return (ans);
}
