/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:31:16 by ski               #+#    #+#             */
/*   Updated: 2022/02/13 10:31:19 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "server.h"

/* ************************************************************************** */
void init_data(t_data *data)
{
	/* Preparation string pid_client ----------------- */
	data->pid_client = 0;
	data->size_stream = 0;
	
	/* Configuration STRUCT SIGACTION ---------------- */
	data->sa.sa_handler = &handler_sig_usr;
	data->sa.sa_flags = SA_RESTART;
    sigaddset(&data->sa.sa_mask, SIGUSR1);
    sigaddset(&data->sa.sa_mask, SIGUSR2);

    /* Configuration BYTE ET BIT --------------------- */
    data->mask = MASK_BIT_7;
    data->byte = 0;
    data->bit_cnt = 0;
    data->byte_cnt = 0;
}

/* ************************************************************************** */
