/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:04:09 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/06/13 23:20:01 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_confirm(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Server received 1 byte.\n");
}

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
			signal(SIGUSR1, sig_confirm);
			send_char(ft_atoi(argv[1]), argv[2][i]);
			i++;
		}
	}
	else
		ft_printf("./client <PID> <your string to send>\n");
	return (0);
}
