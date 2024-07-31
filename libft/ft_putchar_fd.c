/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:29:02 by charlie           #+#    #+#             */
/*   Updated: 2024/03/05 11:29:03 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Outputs the character ’c’ to the given file
// descriptor.

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, sizeof(char));
}
