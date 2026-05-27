/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 20:55:11 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/27 17:45:14 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

void	*monitor_function(void *zip)
{
	t_data		*data;
	t_coders	*coders;
	uint8_t		pos;

	data = ((t_zip *)zip)->data;
	coders = ((t_zip *)zip)->coders;
	pos = 0;
	while (m_retrieve_running_state(data) == true)
	{
		pthread_mutex_lock(&data->enders_mutex);
		if (data->number_of_coders != 1
			&& data->ended_coders >= data->number_of_coders - 1)
			m_switch_running_state(data);
		pthread_mutex_unlock(&data->enders_mutex);
		while (pos != data->number_of_coders)
		{
			if (m_time(data) - coders[pos].last_compile > data->time_to_burnout)
			{
				m_print(&coders[pos], data, "burned out.");
				pthread_mutex_lock(&data->enders_mutex);
				m_switch_running_state(data);
				data->mute = true;
				pthread_mutex_unlock(&data->enders_mutex);
				break ;
			}
			pos++;
		}
		pos = 0;
		usleep(1);
	}
	return ((bool *)true);
}
