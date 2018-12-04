/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 10:48:20 by sregnard          #+#    #+#             */
/*   Updated: 2018/11/14 11:24:38 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_words(char const *s, char c)
{
	int	size;

	size = 0;
	while (s && *s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			size++;
			while (*s && *s != c)
				s++;
		}
	}
	return (size);
}

static	int	ft_strlen_word(char const *s, char c)
{
	int len;

	len = 0;
	while (s && *s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**words;
	char	**p;
	int		size;

	size = count_words(s, c) + 1;
	if ((words = (char **)ft_memalloc(sizeof(char *) * size)) == NULL)
		return (NULL);
	p = words;
	while (s && *s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			size = ft_strlen_word(s, c);
			if ((*words = ft_strnew(size)) == NULL)
				return (NULL);
			*words = ft_strncpy(*words, s, size);
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	*words = 0;
	return (p);
}
