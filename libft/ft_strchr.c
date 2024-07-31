/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:24:00 by charlie           #+#    #+#             */
/*   Updated: 2024/03/15 15:28:14 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
       The  strchr() function returns a pointer to the first occurrence of the
       character c in the string s.

       The strrchr() function returns a pointer to the last occurrence of  the
       character c in the string s.

       The strchrnul() function is like strchr() except that if c is not found
       in s, then it returns a pointer to the null  byte  at  the  end  of  s,
       rather than NULL.

       Here "character" means "byte"; these functions do not work with wide or
       multibyte characters.

RETURN VALUE
       The strchr() and strrchr() functions return a pointer  to  the  matched
       character  or NULL if the character is not found.  The terminating null
       byte is considered part of the string, so that if  c  is  specified  as
       '\0', these functions return a pointer to the terminator.

       The strchrnul() function returns a pointer to the matched character, or
       a pointer to the null byte at the end of s (i.e., s+strlen(s))  if  the
       character is not found.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = (char)c;
	while (*s != '\0')
	{
		if (*s == cc)
			return ((char *)s);
		s++;
	}
	if (cc == '\0')
		return ((char *)s);
	return (NULL);
}
