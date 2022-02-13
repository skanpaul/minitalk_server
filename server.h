/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:31:56 by ski               #+#    #+#             */
/*   Updated: 2022/02/10 19:31:59 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SERVER_H
# define SERVER_H
/* ************************************************************************** */
# include "libft.h"
/* ************************************************************************** */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
/* ************************************************************************** */
# define MASK_BIT_0		1
# define MASK_BIT_1		2
# define MASK_BIT_2		4
# define MASK_BIT_3		8
# define MASK_BIT_4		16
# define MASK_BIT_5		32
# define MASK_BIT_6		64
# define MASK_BIT_7		128
/* ************************************************************************** */
typedef struct s_data
{
	struct	sigaction sa;

	char str_pid_client[5];
	unsigned int pid_client;
	
	char str_size_stream[5];
	unsigned int size_stream;

	unsigned int bit_cnt;
	unsigned int byte_cnt;
	unsigned int byte;
	unsigned int mask;

}	t_data;
/* ************************************************************************** */
void	handler_sig_usr(int sig_c);
void	init_data(t_data *data);
void	init_byte_building(t_data *data);
int		do_pid_client(t_data *data);

/* ************************************************************************** */
#endif
