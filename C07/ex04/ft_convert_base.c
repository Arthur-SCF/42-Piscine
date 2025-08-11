/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:01:02 by asurcouf          #+#    #+#             */
/*   Updated: 2025/02/02 17:29:06 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	check_base(char *base);
int	is_in_base(char str, char *base);
int	atoi_body(int i, char *str, char *base);
int	ft_putnbr_len(int nbr, char *base, int i);

int	aib(char *str, char *base, int i, int neg_count)
{
	int	res;

	res = atoi_body(i, str, base);
	return (res * neg_count);
}

char	*nbrb(int nbr, char *base, int *i, char *res)
{
	int		base_len;
	long	nb;

	nb = nbr;
	base_len = ft_strlen(base);
	if (nb < 0)
	{
		res[*i] = '-';
		nb = -nb;
		(*i)++;
	}
	if (nb >= base_len)
		nbrb((nb / base_len), base, i, res);
	res[(*i)++] = base[nb % base_len];
	return (res);
}

int	test_convert(char *nbr, int *neg_count)
{
	int	i;

	i = 0;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
	i++;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			*neg_count *= -1;
		i++;
	}
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	char	*res;
	int		neg_count;
	int		res_len;
	int		j;

	res_len = 0;
	neg_count = 1;
	if (check_base(base_from) == 1 || check_base(base_to) == 1)
		return (0);
	i = test_convert(nbr, &neg_count);
	res_len = ft_putnbr_len(aib(nbr, base_from, i, neg_count), base_to, 0) + 1;
	res = malloc(sizeof(char) * (res_len + 1));
	if (!res)
		return (NULL);
	j = 0;
	res = nbrb(aib(nbr, base_from, i, neg_count), base_to, &j, res);
	res[j] = '\0';
	return (res);
}
