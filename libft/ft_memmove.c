/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:28:08 by charlie           #+#    #+#             */
/*   Updated: 2024/03/05 10:33:27 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
       The  memmove()  function  copies n bytes from memory area src to memory
       area dest.  The memory areas may overlap: copying takes place as though
       the  bytes in src are first copied into a temporary array that does not
       overlap src or dest, and the bytes are then copied from  the  temporary
       array to dest.

RETURN VALUE
       The memmove() function returns a pointer to dest.
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (d == s)
		return (dest);
	if (s < d && s + n > d)
	{
		s = s + n - 1;
		d = d + n - 1;
		while (n--)
			*d-- = *s--;
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}
