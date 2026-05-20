/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 20:55:11 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/20 12:29:39 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

void	*monitor_function(void *data_addr)
{
	t_data	*data;

	data = (t_data *)data_addr;
	while (data->running == false)
		usleep(1);
	while (data->running == true)
	{
		if (data->ended_coders == data->number_of_coders - 1)
			data->running = false;
	}
	return ((bool *)true);
}
