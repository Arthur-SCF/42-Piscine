/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:48:09 by asurcouf          #+#    #+#             */
/*   Updated: 2025/02/03 17:11:38 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*str;

	i = 0;
	if (min >= max)
		return (0);
	str = malloc(sizeof(int) * (max - min));
	if (!str)
		return (0);
	while (min < max)
	{
		str[i] = min;
		min++;
		i++;
	}
	return (str);
}
