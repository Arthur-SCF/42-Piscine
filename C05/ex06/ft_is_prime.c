/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:30:24 by asurcouf          #+#    #+#             */
/*   Updated: 2025/01/24 13:55:24 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (nb <= 1)
		return (0);
	while (res <= nb && i <= 49340)
	{
		res = i * i;
		if (res == nb)
			return (i);
		i++;
	}
	return (0);
}

int	ft_is_prime(int nb)
{
	int	n;
	int	i;

	n = nb;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	while (ft_sqrt(n) == 0)
		n++;
	i = ft_sqrt(n);
	while (nb % i != 0 && i > 2)
		i--;
	if (nb % i == 0)
		return (0);
	return (1);
}
