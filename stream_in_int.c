/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream_in_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 07:44:11 by ski               #+#    #+#             */
/*   Updated: 2022/02/14 07:44:13 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "server.h"

/* ************************************************************************** */
void	stream_in_int(unsigned int start, unsigned int *val, t_data *d)
{
	if ((0 <= d->byte_cnt) && (d->byte_cnt < (start + 4)))
	{
		*val |= d->byte;
		if (d->byte_cnt < (start + 3))
			*val <<= 8;
	}
	return ;
}
/* ************************************************************************** */
