/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:29:11 by asurcouf          #+#    #+#             */
/*   Updated: 2025/01/16 12:34:39 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_numbers(int a, int b, int c, int d)
{
	while (c <= '9')
	{
		while (d <= '9')
		{
			write(1, &a, 1);
			write(1, &b, 1);
			write(1, " ", 1);
			write(1, &c, 1);
			write(1, &d, 1);
			d++;
			if (a != 9 || b != '8' || c != '9' || d != '9')
			{
				write(1, ",", 1);
				write(1, " ", 1);
			}
		}
		d = c++;
	}
	return (0);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = '0';
	b = '0';
	c = '0';
	d = '1';
	while (a <= '9')
	{
		while (b <= '8')
		{
			print_numbers(a, b, c, d);
			b++;
		}
		b = a++;
	}
}
