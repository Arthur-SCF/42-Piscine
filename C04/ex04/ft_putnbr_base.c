/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:56:14 by asurcouf          #+#    #+#             */
/*   Updated: 2025/01/22 15:45:40 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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
		while (base[j])
		{
			if (i == j)
				j++;
			if (base [i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	nb;

	nb = nbr;
	base_len = ft_strlen(base);
	if (check_base(base) == 1)
		return ;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= base_len)
		ft_putnbr_base((nb / base_len), base);
	ft_putchar(base[nb % base_len]);
}
