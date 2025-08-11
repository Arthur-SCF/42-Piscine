/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:13:53 by asurcouf          #+#    #+#             */
/*   Updated: 2025/01/20 19:52:30 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (dest[i])
	{
		i++;
	}
	while (n < ft_strlen(src))
	{
		dest[i] = src[n];
		i++;
		n++;
	}
	dest[i] = '\0';
	return (dest);
}
