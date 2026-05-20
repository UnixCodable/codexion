/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduling_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 00:39:05 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/20 11:40:25 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

void	s_pop(t_data *data, t_coders *coder)
{
	uint8_t	pos;

	pos = 0;
	while (data->heap[pos]->pos == coder->pos)
		pos++;
	data->heap[pos] = NULL;
	while (true)
	{

	}
}


void	s_add(t_data *data, t_coders *coder)
{
	uint8_t	pos;

	pos = 0;
	while (data->heap[pos] != NULL)
		pos++;
	data->heap[pos] = coder;
}

void	scheduler(t_data *data, t_coders *coders)
{
	while (data->running == true)
		usleep(1);
}
