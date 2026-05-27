/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 01:58:43 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/27 10:44:50 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

bool	refactor(t_coders *thread, t_data *data)
{
	m_print(thread, data, "is refactoring...");
	usleep(data->time_to_refactor * 1000);
	return (true);
}

bool	debug(t_coders *thread, t_data *data)
{
	m_print(thread, data, "is debugging...");
	usleep(data->time_to_debug * 1000);
	return (true);
}

bool	compile(t_coders *thread, t_data *data)
{
	// while (m_retrieve_dongle_state(thread->dongle_left) == true
	// 	&& m_retrieve_dongle_state(thread->dongle_right) == true)
	// 	usleep(1);
	m_dongles_lock(thread, data);
	m_print(thread, data, "is compiling...");
	thread->last_compile = m_time(data);
	usleep(data->time_to_compile * 1000);
	m_dongles_unlock(thread, data);
	return (true);
}

void	*quantum_routine(void *zip)
{
	t_data					*data;
	t_coders				*coder;
	uint16_t				comp;
	static uint8_t			order = 0;

	data = ((t_zip *)zip)->data;
	coder = ((t_zip *)zip)->coders;
	comp = 0;
	while (coder->pos != order + 1)
		usleep(1);
	order++;
	if (coder->pos == data->number_of_coders)
	{
		order = 0;
		m_switch_running_state(data);
	}
	while (m_retrieve_running_state(data) == true || order >= coder->pos)
	{
		compile(coder, data);
		debug(coder, data);
		refactor(coder, data);
		comp++;
		if (comp == data->number_of_compiles_required)
		{
			pthread_mutex_lock(&data->enders_mutex);
			data->ended_coders += 1;
			pthread_mutex_unlock(&data->enders_mutex);
		}
	}
	return ((bool *)true);
}

bool	start_manager(t_data *data, t_coders *coders)
{
	t_zip		*zip;
	t_zip		monitor_zip;
	pthread_t	monitoring;
	uint8_t		pos;

	pos = 0;
	zip = malloc(data->number_of_coders * sizeof(t_zip));
	monitor_zip.coders = coders;
	monitor_zip.data = data;
	if (!zip)
		return (false);
	pthread_create(&monitoring, NULL, monitor_function, &monitor_zip);
	while (pos < data->number_of_coders)
	{
		zip[pos].data = data;
		zip[pos].coders = &coders[pos];
		pthread_create(&coders[pos].coder, NULL, quantum_routine, &zip[pos]);
		pos++;
	}
	pthread_join(monitoring, NULL);
	pos = 0;
	while (pos < data->number_of_coders)
		pthread_join(coders[pos++].coder, NULL);
	free(zip);
	return (true);
}
