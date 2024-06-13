/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                         			:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:34:14 by mguille           #+#    #+#             */
/*   Updated: 2023/02/28 00:34:23 by mguille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	args_check(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc != 3)
	{
		ft_printf("Nombre de paramètre incorecte");
		exit(EXIT_FAILURE);
	}	
	while (argv[1][++i])
	{
		if (!ft_strchr("0123456789", argv[1][i]))
		{
			ft_printf("PID incorrect !");
			exit(EXIT_FAILURE);
		}
	}
	if (*argv[2] == 0)
	{
		ft_printf("Message vide");
		exit(EXIT_FAILURE);
	}
}

void	send_msg(pid_t sv_pid, char *msg)
{
	unsigned char	c;
	int				nbr_bits;

	while (*msg)
	{
		c = *msg;
		nbr_bits = 8;
		while (nbr_bits--)
		{
			if (c & 0b10000000)
				kill(sv_pid, SIGUSR1);
			else
				kill(sv_pid, SIGUSR2);
			usleep(1000);
			c <<= 1;
		}
		msg++;
	}
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR2)
		ft_printf("Message reçu avec succès\n");
}

void	config_signals(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_handler = &sig_handler;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		ft_printf("Echec de la configuration SIGUSR1");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		ft_printf("Echec de la configuration SIGUSR2");
}

int	main(int argc, char **argv)
{
	args_check(argc, argv);
	config_signals();
	send_msg(ft_atoi(argv[1]), argv[2]);
	return (EXIT_SUCCESS);
}
