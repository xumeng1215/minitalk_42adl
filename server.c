/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:21:47 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/06/18 14:16:30 by charlie||        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_receiver(int sig)
{
	int			received_bit;
	static int	bit_count = 0;
	static char	current_char = 0;

	if (sig == SIGUSR1)
		received_bit = 1;
	else
		received_bit = 0;
	current_char = (current_char << 1) | received_bit;
	bit_count++;
	if (bit_count == 8)
	{
		ft_printf("%c", current_char);
		bit_count = 0;
		current_char = 0;
	}
}

int	main(void)
{
	ft_printf("server PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, sig_receiver);
		signal(SIGUSR1, sig_receiver);
		pause();
	}
	return (0);
}
