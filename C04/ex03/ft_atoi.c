/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:56:28 by asurcouf          #+#    #+#             */
/*   Updated: 2025/01/22 18:36:20 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	neg_count;
	int	convertion;

	i = 0;
	convertion = 0;
	neg_count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg_count++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		convertion = convertion * 10 + (str[i] - '0');
		i++;
	}
	if (neg_count % 2 == 1)
		convertion *= -1;
	return (convertion);
}
