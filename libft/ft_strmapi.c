/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:28:21 by charlie           #+#    #+#             */
/*   Updated: 2024/03/05 11:28:22 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Applies the function ’f’ to each character of the
// string ’s’, and passing its index as first argument
// to create a new string (with malloc(3)) resulting
// from successive applications of ’f’.

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	s_len;
	unsigned int	idx;
	char			*result;

	s_len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (s_len + 1));
	if (result == NULL)
		return (NULL);
	idx = 0;
	while (idx < s_len)
	{
		result[idx] = f(idx, s[idx]);
		idx++;
	}
	result[idx] = '\0';
	return (result);
}
