/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:19:41 by asurcouf          #+#    #+#             */
/*   Updated: 2025/01/15 19:03:10 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//print numbers like this: 'xxx, '
int	print_nb(int a, int b, int c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a != '7' || b != '8' || c != '9')
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
	return (0);
}

void	ft_print_comb(void)
{
	int	f;
	int	g;
	int	h;

	f = '0';
	g = '1';
	h = '2';
	while (f <= '7')
	{
		while (g <= '8')
		{
			while (h <= '9')
			{
				print_nb(f, g, h);
				h++;
			}
			g++;
			h = g + 1;
		}
		f++;
		g = f;
	}	
}
