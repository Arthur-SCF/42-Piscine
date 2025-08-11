/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:53:51 by asurcouf          #+#    #+#             */
/*   Updated: 2025/01/20 17:12:45 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	convert_d_to_h(char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[(unsigned char) c / 16]);
	ft_putchar(hex[(unsigned char) c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32)
		{
			ft_putchar('\\');
			convert_d_to_h(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
