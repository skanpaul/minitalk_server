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
void handler_sig_usr(int sig_c);

/* ************************************************************************** */
t_data data;

/* ************************************************************************** */
int main(void)
{
	int pid_server;
	/* INITIALISATION -------------------------------- */
	init_data(&data);
	init_byte_building(&data);
	/* Affichage PID server -------------------------- */
	pid_server = getpid();	
	ft_printf("PID server: %d \n", pid_server);
	/* Link SIGNAL with HANDLER ---------------------- */
	sigaction(SIGUSR1, &data.sa, 0);
	sigaction(SIGUSR2, &data.sa, 0);
	/* ATTENTE DE SIGNAL ----------------------------- */
	while (1) pause();
	/* ----------------------------------------------- */
	return (0);
}

/* ************************************************************************** */
void handler_sig_usr(int sig_c)
{
	/* ----------------------------------------------- */
	if (sig_c == SIGUSR2)
		data.byte = data.byte | data.mask;		
	data.bit_cnt++;
	data.mask >>= 1;	
	/* ----------------------------------------------- */
	if(data.bit_cnt == 8)
	{
		// printf("byte[%d] - caractere: %#02x\n", data.byte_cnt, data.byte);		
		/* PID client ------------------------------------ */
		if ((0 <= data.byte_cnt) && (data.byte_cnt < 4))
			data.pid_client |= data.byte;
			if (data.byte_cnt < 3)
				data.pid_client <<= 8;
		// /* SIZE stream ----------------------------------- */
		if ((4 <= data.byte_cnt) && (data.byte_cnt < 8))
			data.size_stream |= data.byte;
			if (data.byte_cnt < 7)
				data.size_stream <<= 8;
		/* ----------------------------------------------- */
		if (data.byte_cnt == 7)
		{
			data.str = (char *)malloc(data.size_stream * sizeof(char));
			if (!data.str)
				exit(1);
			// printf("malloc OK\n");
		}
		/* ----------------------------------------------- */
		if (8 <= data.byte_cnt)
		{
			if(data.byte_cnt < (data.size_stream + 8))
			{
				// printf("fabrique string: str[%d] = [%c]\n", data.i, (char)data.byte);
				data.str[data.i] = (char)data.byte;
				data.i++;
			}		
			if (data.byte_cnt == (data.size_stream + 8 - 1))
			{
				// printf("Dans le write - byte[%d]\n", data.byte_cnt);
				write(1, data.str, data.size_stream);
				write(1, "\n", 1);
				free (data.str);
				sleep(1);
				kill(data.pid_client, SIGUSR1);
				init_data(&data);
				return ;
			}
		}

		/* ----------------------------------------------- */
		data.byte = 0;
		data.byte_cnt++;	
		data.bit_cnt = 0;
		data.mask = MASK_BIT_7;
		/* ----------------------------------------------- */
		if (data.byte_cnt == 4) printf("PID client:\t[%u]\n", data.pid_client);
		if (data.byte_cnt == 8) printf("Size Stream:\t[%u]\n", data.size_stream);
		/* ----------------------------------------------- */

	}
	/* ----------------------------------------------- */
	// METTRE data_byte_cnt à ZERO
	// FREE LE MALLOC
	// remettre i 0
}

/* ************************************************************************** */