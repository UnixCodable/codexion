/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 01:58:43 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/19 18:00:29 by lbordana         ###   ########.fr       */
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
	m_dongles_lock(thread, data);
	m_print(thread, data, "is compiling...");
	thread->last_compile = m_time(data);
	usleep(data->time_to_compile * 1000);
	m_dongles_unlock(thread, data);
	return (true);
}

void	*quantum_code(void *zip)
{
	uint16_t				comp;
	t_data					*data;
	t_coders				*coder;

	comp = 0;
	data = ((t_zip *)zip)->data;
	coder = ((t_zip *)zip)->coders;
	while (data->running == false)
		usleep(1);
	while (true)
	{
		compile(coder, data);
		debug(coder, data);
		refactor(coder, data);
		comp++;
	}
	data->ended_coders += 1;
	return ((bool *)true);
}

bool	start_manager(t_data *data, t_coders *coders)
{
	t_zip		*zip;
	pthread_t	monitoring;
	uint8_t		pos;

	pos = 0;
	zip = malloc(data->number_of_coders * sizeof(t_zip));
	if (!zip)
		return (false);
	pthread_create(&monitoring, NULL, monitor_function, data);
	while (pos < data->number_of_coders)
	{
		zip[pos].data = data;
		zip[pos].coders = &coders[pos];
		pthread_create(&coders[pos].coder, NULL, quantum_code, &zip[pos]);
		pos++;
	}
	data->running = true;
	pthread_join(monitoring, NULL);
	free(zip);
	return (true);
}
