/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:31:05 by charlie           #+#    #+#             */
/*   Updated: 2024/03/05 11:31:10 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*result;
	char		cc;

	cc = (char)c;
	result = NULL;
	while (*s != '\0')
	{
		if (*s == cc)
			result = s;
		s++;
	}
	if (cc == '\0')
		return ((char *)s);
	return ((char *)result);
}
