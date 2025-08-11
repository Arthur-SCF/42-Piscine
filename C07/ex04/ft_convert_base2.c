/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:37:06 by asurcouf          #+#    #+#             */
/*   Updated: 2025/02/03 17:18:45 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i++);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[i] == '\0' || base[i + 1] == '\0')
		return (1);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = 0;
		while (j < ft_strlen(base))
		{
			if (i == j)
				j++;
			if (base [i] == base[j])
				return (1);
			j++;
		}
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (1);
		i++;
	}
	return (0);
}

int	is_in_base(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (str == base[i])
			return (i);
		else
			i++;
	}
	return (-1);
}

int	atoi_body(int i, char *str, char *base)
{
	int	base_len;
	int	res;

	res = 0;
	base_len = ft_strlen(base);
	while (str[i] && is_in_base(str[i], base) != -1)
	{
		res = res * base_len + is_in_base(str[i], base);
		i++;
	}
	return (res);
}

int	ft_putnbr_len(int nbr, char *base, int i)
{
	int			base_len;
	long		nb;

	nb = nbr;
	base_len = ft_strlen(base);
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	if (nb >= base_len)
		ft_putnbr_len((nb / base_len), base, i);
	i++;
	return (i);
}
