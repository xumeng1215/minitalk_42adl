/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschilli <jschilli@student.42.au>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:58:54 by jschilli          #+#    #+#             */
/*   Updated: 2024/03/20 14:28:52 by jschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	arrsize(char const *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	len;
	int		i;

	i = 0;
	split = malloc((arrsize(s, c) + 1) * sizeof(char *));
	if (!split || !s)
		return (NULL);
	while (*s != '\0')
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, c) - s;
			split[i++] = ft_substr(s, 0, len);
			s += len;
		}
	}
	split[i] = NULL;
	return (split);
}
