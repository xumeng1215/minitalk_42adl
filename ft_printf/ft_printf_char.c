/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:27:57 by charlie|mex       #+#    #+#             */
/*   Updated: 2024/06/07 13:41:47 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_strlen2(const char *s)
{
	unsigned int	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *s)
{
	if (s == NULL)
		return (write(1, "(null)", 6));
	else
		return (write(1, s, ft_strlen2(s)));
}
