/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:29:38 by ski               #+#    #+#             */
/*   Updated: 2022/02/08 15:29:40 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "server.h"

/* ************************************************************************** */
void	handler_sig_usr(int sig_c);

/* ************************************************************************** */
t_data	g_d;

/* ************************************************************************** */
int	main(void)
{
	int	pid_server;

	init_data_server(&g_d);
	pid_server = getpid();
	ft_printf("PID server: %d \n", pid_server);
	sigaction(SIGUSR1, &g_d.sa, 0);
	sigaction(SIGUSR2, &g_d.sa, 0);
	while (1)
		pause();
	return (0);
}

/* ************************************************************************** */
void	handler_sig_usr(int sig_c)
{
	int	should_return;

	if (sig_c == SIGUSR2)
		g_d.byte = g_d.byte | g_d.mask;
	g_d.bit_cnt++;
	g_d.mask >>= 1;
	if (g_d.bit_cnt == 8)
	{
		stream_in_int(0, &g_d.pid_client, &g_d);
		stream_in_int(4, &g_d.size_stream, &g_d);
		if (g_d.byte_cnt == 7)
		{
			g_d.str = (char *)malloc(g_d.size_stream * sizeof(char));
			if (!g_d.str)
				exit(1);
		}
		should_return = stream_in_str(8, g_d.str, &g_d);
		if (should_return)
			return ;
		g_d.byte = 0;
		g_d.byte_cnt++;
		g_d.bit_cnt = 0;
		g_d.mask = MASK_BIT_7;
	}
}
/* ************************************************************************** */