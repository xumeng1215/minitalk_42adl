/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:28:02 by charlie           #+#    #+#             */
/*   Updated: 2024/03/13 21:34:36 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates (with malloc(3)) and returns a string
// representing the integer received as an argument.
// Negative numbers must be handled.

#include "libft.h"

unsigned short	ft_count_digits(int num)
{
	unsigned short	i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		i++;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned short	digits;

	digits = ft_count_digits(n);
	result = (char *)malloc(sizeof(char) * (digits + 1));
	if (result == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_memcpy(result, "-2147483648\0", 12));
	if (n < 0)
	{
		result[0] = '-';
		n = -1 * n;
	}
	if (n == 0)
		result[0] = '0';
	result[digits] = '\0';
	while (n != 0)
	{
		result[digits - 1] = n % 10 + '0';
		n = n / 10;
		digits--;
	}
	return (result);
}
