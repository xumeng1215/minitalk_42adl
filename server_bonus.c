/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:41:44 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/06/18 14:16:46 by charlie||        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sig_receiver(int sig, siginfo_t *info, void *context)
{
	static int	bit_count = 0;
	static char	current_char = 0;
	int			received_bit;

	(void)context;
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
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("server PID: %d\n", getpid());
	sig.sa_sigaction = sig_receiver;
	sig.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
	return (0);
}
