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

	init_data(&g_d);
	init_byte_building(&g_d);
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
	/* ----------------------------------------------- */
	if (sig_c == SIGUSR2)
		g_d.byte = g_d.byte | g_d.mask;
	g_d.bit_cnt++;
	g_d.mask >>= 1;
	/* ----------------------------------------------- */
	if (g_d.bit_cnt == 8)
	{
		/* PID client ------------------------------------ */
		stream_in_int(0, &g_d.pid_client, &g_d);
		// if ((0 <= g_d.byte_cnt) && (g_d.byte_cnt < 4))
		// {
		// 	g_d.pid_client |= g_d.byte;
		// 	if (g_d.byte_cnt < 3)
		// 		g_d.pid_client <<= 8;
		// }
		// /* SIZE stream ----------------------------------- */

		stream_in_int(4, &g_d.size_stream, &g_d);
		// if ((4 <= g_d.byte_cnt) && (g_d.byte_cnt < 8))
		// {
		// 	g_d.size_stream |= g_d.byte;
		// 	if (g_d.byte_cnt < 7)
		// 		g_d.size_stream <<= 8;
		// }
		/* ----------------------------------------------- */
		if (g_d.byte_cnt == 7)
		{
			g_d.str = (char *)malloc(g_d.size_stream * sizeof(char));
			if (!g_d.str)
				exit(1);
		}
		/* ----------------------------------------------- */
		if (8 <= g_d.byte_cnt)
		{
			if (g_d.byte_cnt < (g_d.size_stream + 8))
			{
				g_d.str[g_d.i] = (char)g_d.byte;
				g_d.i++;
			}		
			if (g_d.byte_cnt == (g_d.size_stream + 8 - 1))
			{
				write(1, g_d.str, g_d.size_stream);
				write(1, "\n", 1);
				free (g_d.str);
				usleep(100000);
				kill(g_d.pid_client, SIGUSR1);
				init_data(&g_d);
				return ;
			}
		}
		/* ----------------------------------------------- */
		g_d.byte = 0;
		g_d.byte_cnt++;
		g_d.bit_cnt = 0;
		g_d.mask = MASK_BIT_7;
		/* ----------------------------------------------- */
		if (g_d.byte_cnt == 4)
			printf("PID client:\t[%u]\n", g_d.pid_client);
		if (g_d.byte_cnt == 8)
			printf("Size Stream:\t[%u]\n", g_d.size_stream);
	}
}
/* ************************************************************************** */