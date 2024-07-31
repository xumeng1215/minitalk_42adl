/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:25:24 by charlie           #+#    #+#             */
/*   Updated: 2024/03/05 11:25:25 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		negitive_sign;
	int		result;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	negitive_sign = 1;
	result = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negitive_sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * negitive_sign);
}
