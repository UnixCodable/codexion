/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 20:55:11 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/28 15:22:41 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

bool	check_time(t_coders *coders, t_data *data)
{
	uint8_t		pos;

	pos = 0;
	while (pos != data->number_of_coders)
	{
		pthread_mutex_lock(&coders[pos].time_mutex);
		if (m_time(data) - coders[pos].last_compile > data->time_to_burnout)
		{
			pthread_mutex_lock(&data->print_mutex);
			data->mute = true;
			pthread_mutex_unlock(&data->print_mutex);
			usleep(1000);
			m_switch_running_state(data);
			pthread_mutex_lock(&data->enders_mutex);
			m_print(&coders[pos], data, "burned out.", true);
			pthread_mutex_unlock(&data->enders_mutex);
			pthread_mutex_unlock(&coders[pos].time_mutex);
			return (false);
		}
		pthread_mutex_unlock(&coders[pos].time_mutex);
		pos++;
	}
	return (true);
}

void	*monitor_function(void *zip)
{
	t_data		*data;
	t_coders	*coders;

	data = ((t_zip *)zip)->data;
	coders = ((t_zip *)zip)->coders;
	while (m_retrieve_running_state(data) == true)
	{
		pthread_mutex_lock(&data->enders_mutex);
		if (data->number_of_coders != 1
			&& data->ended_coders >= data->number_of_coders - 1)
			m_switch_running_state(data);
		pthread_mutex_unlock(&data->enders_mutex);
		if (check_time(coders, data) == false)
			break ;
		usleep(1);
	}
	return ((bool *)true);
}
