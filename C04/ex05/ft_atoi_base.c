/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:14:57 by asurcouf          #+#    #+#             */
/*   Updated: 2025/01/22 18:52:08 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (0);
}

int	atoi_body(int i, char *str, char *base)
{
	int	base_len;
	int	res;

	res = 0;
	base_len = ft_strlen(base);
	while (str[i] && is_in_base(str[i], base) != 0)
	{
		res = res * base_len + is_in_base(str[i], base);
		i++;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	neg_count;
	int	res;

	i = 0;
	neg_count = 0;
	if (check_base(base) == 1)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg_count++;
		i++;
	}
	res = atoi_body(i, str, base);
	if (neg_count % 2 == 1)
		res *= -1;
	return (res);
}
