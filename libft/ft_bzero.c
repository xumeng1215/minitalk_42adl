/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:07:36 by charlie           #+#    #+#             */
/*   Updated: 2024/03/05 10:11:01 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
       The  bzero()  function  erases  the  data  in the n bytes of the memory
       starting at the location pointed to by s, by writing zeros (bytes  con‐
       taining '\0') to that area.

       The  explicit_bzero()  function  performs the same task as bzero().  It
       differs from bzero() in that it guarantees that compiler  optimizations
       will  not  remove  the erase operation if the compiler deduces that the
       operation is "unnecessary".

RETURN VALUE
       None.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}
