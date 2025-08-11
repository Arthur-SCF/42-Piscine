/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:13:57 by asurcouf          #+#    #+#             */
/*   Updated: 2025/02/05 16:09:52 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	word_len(int index, char *str, char *charset)
{
	int	j;

	j = index;
	while (str[j] && in_charset(str[j], charset) == 0)
		j++;
	return (j - index);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] && in_charset(str[i], charset) == 1)
			i++;
		if (str[i])
			n++;
		while (str[i] && in_charset(str[i], charset) == 0)
			i++;
	}
	return (n);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**res;

	res = malloc(sizeof(char *) * (count_word(str, charset) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && in_charset(str[i], charset) == 1)
			i++;
		if (j < count_word(str, charset))
		{
			res[j] = malloc(word_len(i, str, charset) + 1);
			if (res[j] == NULL)
				return (NULL);
			ft_strncpy(res[j], &str[i], word_len(i, str, charset));
			j++;
			i += word_len(i, str, charset);
		}
	}
	res[j] = 0;
	return (res);
}
