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
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
// # include "libft.h"
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
	struct sigaction sa;
	// struct sigaction sa_old;
	int	bit_cnt;
	int byte_cnt;
	int byte;
	int mask;
}	t_data;
/* ************************************************************************** */
void	handler_sig_usr(int sig_c);
void	init_data(t_data *data);

/* ************************************************************************** */
#endif

