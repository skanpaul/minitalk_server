/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_server.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:31:16 by ski               #+#    #+#             */
/*   Updated: 2022/02/13 10:31:19 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "server.h"

/* ************************************************************************** */
void	init_data_server(t_data *d)
{
	d->pid_client = 0;
	d->size_stream = 0;
	d->str = NULL;
	d->i = 0;
	d->sa.sa_handler = &handler_sig_usr;
	d->sa.sa_flags = SA_RESTART;
	sigemptyset(&d->sa.sa_mask);
	sigaddset(&d->sa.sa_mask, SIGUSR1);
	sigaddset(&d->sa.sa_mask, SIGUSR2);
	d->mask = MASK_BIT_7;
	d->byte = 0;
	d->bit_cnt = 0;
	d->byte_cnt = 0;
}

/* ************************************************************************** */
