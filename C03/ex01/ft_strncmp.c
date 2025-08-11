/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:38:48 by asurcouf          #+#    #+#             */
/*   Updated: 2025/01/20 19:52:00 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && (s1[i] == s2[i]) && s1[i] != '\0')
		i++;
	if (s1[i] == s2[i])
		return (0);
	else
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
