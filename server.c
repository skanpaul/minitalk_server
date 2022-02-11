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
t_data data;
/* ************************************************************************** */
void handler_sig_usr(int sig_c);

/* ************************************************************************** */
int main(void)
{
	int pid_server;

	pid_server = getpid();
	
	ft_printf("Server PID: %d \n", pid_server);

	data.sa.sa_handler = &handler_sig_usr;
	data.sa.sa_flags = SA_RESTART;
	data.sa.sa_mask = 0xFFFFFFFF;  // A VERIFIER LE COMPORTEMENT CORRECTE OU PAS

	sigaction(SIGUSR1, &data.sa, 0);
	sigaction(SIGUSR2, &data.sa, 0);

	while (1) ;
	return (0);
}

/* ************************************************************************** */
void handler_sig_usr(int sig_c)
{
	if (sig_c == SIGUSR1) ft_printf("0 reçu\n");
	if (sig_c == SIGUSR2) ft_printf("1 reçu\n");
}

/* ************************************************************************** */