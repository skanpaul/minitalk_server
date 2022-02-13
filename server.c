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
	printf("PID server: %d \n", pid_server);
	/* Link SIGNAL with HANDLER ---------------------- */
	sigaction(SIGUSR1, &data.sa, 0);
	sigaction(SIGUSR2, &data.sa, 0);
	/* ATTENTE DE SIGNAL ----------------------------- */
	while (1) 
	{

		pause();
	}
	/* ----------------------------------------------- */
	return (0);
}

/* ************************************************************************** */
void handler_sig_usr(int sig_c)
{
	// char *bidon = "3621";
	/* ----------------------------------------------- */
	if (sig_c == SIGUSR2)
		data.byte = data.byte | data.mask;		
	data.bit_cnt++;
	data.mask >>= 1;	

	/* ----------------------------------------------- */
	if(data.bit_cnt == 8)
	{
		printf("byte[%d] - caractere: %x\n", data.byte_cnt, data.byte);
		
		/* PID client ------------------------------------ */
		if (data.byte_cnt < 4)
			// data.str_pid_client[data.byte_cnt] = data.byte;
			printf("Avant: %#010x\n", data.pid_client);
			data.pid_client |= data.byte;
			if (data.byte_cnt < 3)
				data.pid_client <<= 8;
			printf("Apres: %#010x\n", data.pid_client);

		if (data.byte_cnt == 3)
		{
			// data.pid_client = (unsigned int)ft_atoi(data.str_pid_client);
			printf("\nbyte[%d] - PID client: %u\n\n", data.byte_cnt, data.pid_client);
		}
		/* SIZE stream ----------------------------------- */
		if ((4 <= data.byte_cnt) && (data.byte_cnt < 8))
			data.str_size_stream[data.byte_cnt - 4] = data.byte;
		if (data.byte_cnt == 7)
		{
			data.size_stream = (unsigned int)ft_atoi(data.str_size_stream);
			printf("\nbyte[%d] - Size Stream: %u\n\n", data.byte_cnt, data.size_stream);
		}

		/* ----------------------------------------------- */
		data.byte = 0;
		data.byte_cnt++;
	
		data.bit_cnt = 0;
		data.mask = MASK_BIT_7;
	}
	/* ----------------------------------------------- */
	// METTRE data_byte_cnt à ZERO
}

/* ************************************************************************** */