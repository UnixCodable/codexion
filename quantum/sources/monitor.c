/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 20:55:11 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/21 01:34:04 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

void	*monitor_function(void *data_addr)
{
	t_data	*data;

	data = (t_data *)data_addr;
	while (m_retrieve_running_state(data) == false)
		usleep(1);
	while (m_retrieve_running_state(data) == true)
	{
		pthread_mutex_lock(&data->enders_mutex);
		if (data->ended_coders == data->number_of_coders - 1)
			m_switch_running_state(data);
		pthread_mutex_unlock(&data->enders_mutex);
	}
	return ((bool *)true);
}
