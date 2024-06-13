/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:34:14 by mguille           #+#    #+#             */
/*   Updated: 2023/02/28 00:34:23 by mguille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//vérifie les arguments en ligne de commande passés au programme
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

//envoi du message caractère par caractère au processus serveur
void	send_msg(int pid_adr, char msg)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((msg & (0x01 << bit)))
			kill(pid_adr, SIGUSR1);
		else
			kill(pid_adr, SIGUSR2);
		usleep(1000);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	ft_printf("PID DU CLIENT = %d\n\n", getpid());
	args_check(argc, argv);
	while (argv[2][i] != '\0')
	{
		send_msg(ft_atoi(argv[1]), argv[2][i]);
		i++;
	}
	return (0);
}
