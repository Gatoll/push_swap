/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:05:43 by kaokazak          #+#    #+#             */
/*   Updated: 2024/09/11 16:07:11 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_issep_multi(char s, char *c)
{
	while (*c != '\0')
	{
		if (s == *c)
			return (1);
		c++;
	}
	return (0);
}

static char	*ft_copy_word_multi(const char *str, char *c)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (str[len] && !ft_issep_multi(str[len], c))
		len++;
	word = (char *)ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	return (word);
}

static int	ft_count_words_multi(char const *s, char *c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (!ft_issep_multi(s[i], c))
		{
			count++;
			while (s[i] != '\0' && !ft_issep_multi(s[i], c))
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_free_multi(char **str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split_multi(char const *s, char *c)
{
	char	**res;
	int		i;

	if (!s || *s == '\0')
		return (NULL);
	res = (char **)ft_calloc(ft_count_words_multi(s, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		if (!ft_issep_multi(*s, c))
		{
			res[i] = ft_copy_word_multi(s, c);
			if (!res[i])
				return (ft_free_multi(res, i));
			while (*s != '\0' && !ft_issep_multi(*s, c))
				s++;
			i++;
		}
		else
			s++;
	}
	return (res);
}
