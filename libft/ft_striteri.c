/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:28:44 by charlie           #+#    #+#             */
/*   Updated: 2024/03/05 11:28:45 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Applies the function ’f’ on each character of
// the string passed as argument, passing its index
// as first argument. Each character is passed by
// address to ’f’ to be modified if necessary.

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	idx;

	idx = 0;
	while (*s != '\0')
	{
		f(idx, s);
		s++;
		idx++;
	}
}
