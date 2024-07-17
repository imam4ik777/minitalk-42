/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatakis <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:59:13 by imatakis          #+#    #+#             */
/*   Updated: 2024/07/17 19:01:07 by imatakis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sender_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if ((c & (1 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep (100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			sender_char(pid, argv[2][i]);
			i++;
		}
		sender_char(pid, '\n');
	}
	else
	{
		write (1, "Error: Wrong Format\n", 20);
		write (1, "Try: ./client <PID> <MESSAGE>\n", 30);
		return (1);
	}
	return (0);
}
