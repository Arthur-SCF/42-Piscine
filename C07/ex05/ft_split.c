/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:12:10 by asurcouf          #+#    #+#             */
/*   Updated: 2025/02/03 17:06:50 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int	count_words(char *str, char *charset)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		while (str[i] && in_charset(str[i], charset) == 1)
			i++;
		if (str[i])
			w++;
		while (str[i] && in_charset(str[i], charset) == 0)
			i++;
	}
	return (w);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (*src && i < n)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str, char *charset)
{
	int	a;

	a = 0;
	while (*str && in_charset(*str, charset) == 0)
	{
		str++;
		a++;
	}
	return (a);
}

char	**ft_split(char *str, char *charset)
{
	int		j;
	char	**final;

	j = 0;
	final = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!final)
		return (NULL);
	while (*str && j < count_words(str, charset))
	{
		while (*str && in_charset(*str, charset) == 1)
			str++;
		final[j] = malloc(sizeof(char) * ft_strlen(str, charset) + 1);
		if (final[j])
			ft_strncpy(final[j], str, ft_strlen(str, charset));
		while (*str && in_charset(*str, charset) == 0)
			str++;
		j++;
	}
	final[j] = 0;
	return (final);
}
