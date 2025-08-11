/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:13:29 by asurcouf          #+#    #+#             */
/*   Updated: 2025/02/03 17:28:48 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	total_len(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len += (ft_strlen(sep) * (size - 1)) + 1;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*s1;

	i = 0;
	if (size == 0)
	{
		s1 = malloc(1);
		s1[0] = 0;
		return (s1);
	}
	s1 = malloc(sizeof(char) * total_len(size, strs, sep));
	s1[0] = '\0';
	if (!s1)
		return (NULL);
	while (i < size)
	{
		ft_strcat(s1, strs[i]);
		if (i < size - 1)
			ft_strcat(s1, sep);
		i++;
	}
	return (s1);
}
