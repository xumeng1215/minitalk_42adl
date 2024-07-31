/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:22:16 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/05/17 16:24:56 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if (c >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc == 3)
	{
		i = 0;
		while (argv[2][i] != '\0')
		{
			send_char(ft_atoi(argv[1]), argv[2][i]);
			i++;
		}
	}
	else
		ft_printf("./client <PID> <your string to send>\n");
	return (0);
}
