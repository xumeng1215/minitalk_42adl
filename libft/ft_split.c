/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:27:50 by charlie           #+#    #+#             */
/*   Updated: 2024/03/05 11:27:51 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates (with malloc(3)) and returns an array
// of strings obtained by splitting ’s’ using the
// character ’c’ as a delimiter. The array must end
// with a NULL pointer.

#include "libft.h"

int	count_words(const char *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str != '\0')
	{
		if (*str == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

char	**mapping_word(char **result, const char *str, char c)
{
	int			index;
	int			in_word;
	const char	*start;

	index = 0;
	in_word = 0;
	start = str;
	while (*str != '\0')
	{
		if (*str == c)
		{
			if (in_word)
				result[index++] = ft_substr(start, 0, str - start);
			in_word = 0;
		}
		else if (!in_word)
		{
			start = str;
			in_word = 1;
		}
		str++;
	}
	if (in_word)
		result[index] = ft_substr(start, 0, str - start);
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		num_words;
	char	**result;

	num_words = count_words(s, c);
	result = (char **)malloc((num_words + 1) * sizeof(char *));
	if (result == NULL)
		return (0);
	mapping_word(result, s, c);
	result[num_words] = 0;
	return (result);
}

/*
int main() {
    char *str = "aab22c2b33a3d4444akkkk";
    char spliter = 'a';
    char **result = ft_split(str, spliter);

    for (int i = 0; result[i] != NULL; i++) {
        printf("%s\n", result[i]);
    }
    for (int i = 0; result[i] != NULL; i++) {
        free(result[i]);
    }
	free(result);
    return 0;
}
*/