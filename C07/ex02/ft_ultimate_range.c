/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:48:18 by asurcouf          #+#    #+#             */
/*   Updated: 2025/01/30 14:26:05 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*str;
	int	len;

	i = 0;
	len = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	str = malloc(sizeof(int) * len);
	if (!str)
		return (-1);
	while (min < max)
	{
		str[i] = min;
		min++;
		i++;
	}
	*range = str;
	return (len);
}
