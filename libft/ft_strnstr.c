/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:30:39 by charlie           #+#    #+#             */
/*   Updated: 2024/03/12 12:25:18 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The strnstr() function locates the first occurrence of the null-terminated
     string little in the string big, where not more than len characters are
     searched.  Characters that appear after a ‘\0’ character are not searched.
     Since the strnstr() function is a FreeBSD specific API, it should only be 
     used when portability is not a concern.

RETURN VALUES
     If little is an empty string, big is returned; if little occurs nowhere in
     big, NULL is returned; otherwise a pointer to the first character of the 
     first occurrence of little is returned.
*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	idx;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	while (*big != '\0' && little_len <= len)
	{
		idx = 0;
		while (*(big + idx) == *(little + idx) && idx < little_len)
			idx++;
		if (idx == little_len)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
