/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:26:04 by charlie           #+#    #+#             */
/*   Updated: 2024/03/12 12:44:07 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
       The  strdup() function returns a pointer to a new string which is a du‐
       plicate of the string s.  Memory for the new string  is  obtained  with
       malloc(3), and can be freed with free(3).

       The strndup() function is similar, but copies at most n bytes.  If s is
       longer than n, only n bytes are copied, and  a  terminating  null  byte
       ('\0') is added.

       strdupa() and strndupa() are similar, but use alloca(3) to allocate the
       buffer.  They are available only when using the GNU GCC suite, and suf‐
       fer from the same limitations described in alloca(3).

RETURN VALUE
       On  success,  the strdup() function returns a pointer to the duplicated
       string.  It returns NULL if insufficient memory was available, with er‐
       rno set to indicate the cause of the error.

*/

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str_dup;
	size_t	str_len;

	str_len = ft_strlen(str);
	str_dup = (char *)malloc(sizeof(char) * (str_len + 1));
	if (str_dup == NULL)
		return (NULL);
	str_len = ft_strlcpy(str_dup, str, (str_len + 1));
	return (str_dup);
}
