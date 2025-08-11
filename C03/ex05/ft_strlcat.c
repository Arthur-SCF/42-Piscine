/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:46:11 by asurcouf          #+#    #+#             */
/*   Updated: 2025/01/21 13:55:17 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	res;
	unsigned int	i;
	unsigned int	ld;
	unsigned int	ls;

	i = 0;
	ld = ft_strlen(dest);
	ls = ft_strlen(src);
	if (size > ld)
		res = ls + ld;
	else
		res = ls + size;
	while (src[i] != '\0' && ld <= size)
	{
		dest[ld] = src[i];
		i++;
		ld++;
	}
	dest[ld] = '\0';
	return (res);
}
