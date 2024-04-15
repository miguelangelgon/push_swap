/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:31:11 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/12 11:23:12 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(ft_strlen(s1) + 1);
	if (copy == 0)
		return (0);
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*a;
	unsigned int	i;

	if (!s || start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (a == '\0')
		return (0);
	i = 0;
	while (len--)
	{
		a[i] = s[i + start];
		i++;
	}
	a[i] = '\0';
	return (a);
}
static void	ft_free(char **res)
{
	int	i;

	i = -1;
	while (res[++i])
		free(res[i]);
	free(res);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
			word++;
		i++;
	}
	return (word);
}

static char	**write_result(char const *s, char c, char **res)
{
	size_t	start;
	size_t	i;
	size_t	word;

	start = 0;
	i = 0;
	word = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
		{
			res[word] = ft_substr(s, start, i - start + 1);
			if (!res[word])
			{
				ft_free(res);
				return (0);
			}
			word++;
		}
		if (s[i] == c && (s[i + 1] != c || s[i + 1] != '\0'))
			start = i + 1;
		i++;
	}
	res[word] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**res;

	i = 0;
	if (!s)
		return (0);
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (0);
	res = write_result(s, c, res);
	return (res);
}

