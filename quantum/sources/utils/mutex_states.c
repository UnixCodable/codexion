/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 01:08:33 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/29 14:29:58 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

int	s_retrieve(t_dongle *dongle)
{
	int	coder_pos;

	coder_pos = -1;
	pthread_mutex_lock(&dongle->dongle_heap);
	if (dongle->priority_queue[0])
		coder_pos = dongle->priority_queue[0]->pos;
	pthread_mutex_unlock(&dongle->dongle_heap);
	return (coder_pos);
}

bool	m_retrieve_dongle_state(t_dongle *dongle, t_data *data)
{
	bool	is_unlock;

	pthread_mutex_lock(&dongle->dongle_state);
	if (dongle->last_used == 0
		|| m_time(data) - dongle->last_used >= data->dongle_cooldown)
		is_unlock = false;
	else
		is_unlock = true;
	pthread_mutex_unlock(&dongle->dongle_state);
	return (is_unlock);
}

bool	m_retrieve_running_state(t_data *data)
{
	bool	is_unlock;

	pthread_mutex_lock(&data->running_mutex);
	if (data->running == true)
		is_unlock = true;
	else
		is_unlock = false;
	pthread_mutex_unlock(&data->running_mutex);
	return (is_unlock);
}

void	m_switch_running_state(t_data *data)
{
	pthread_mutex_lock(&data->running_mutex);
	if (data->running == true)
		data->running = false;
	else
		data->running = true;
	pthread_mutex_unlock(&data->running_mutex);
}
