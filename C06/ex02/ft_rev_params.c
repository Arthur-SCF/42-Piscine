/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:16:19 by asurcouf          #+#    #+#             */
/*   Updated: 2025/01/24 14:22:39 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	int	i;

	i = argc - 1;
	if (argc <= 1)
		return (0);
	while (i > 0)
	{
		ft_putstr(argv[i]);
		i--;
	}
	return (0);
}
