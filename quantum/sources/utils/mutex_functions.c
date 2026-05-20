/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 12:03:59 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/21 00:40:31 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

void	m_switch_dongle_state(t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->dongle_state);
	if (dongle->is_locked == true)
		dongle->is_locked = false;
	else
		dongle->is_locked = true;
	pthread_mutex_unlock(&dongle->dongle_state);
}

bool	m_retrieve_dongle_state(t_dongle *dongle)
{
	bool	is_unlock;

	pthread_mutex_lock(&dongle->dongle_state);
	if (dongle->is_locked == true)
		is_unlock = true;
	else
		is_unlock = false;
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

void	m_print(t_coders *thread, t_data *data, char *str)
{
	static pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&mutex);
	printf("\033[1;38;2;%lu;%lu;%lum %ld %u %s \033[0m\n",
		(uint64_t)thread->dongle_left % 255,
		(uint64_t)thread->dongle_right % 255,
		(uint64_t) &(thread->pos) % 255, m_time(data), thread->pos, str);
	pthread_mutex_unlock(&mutex);
}

void	m_dongles_lock(t_coders *thread, t_data *data)
{
	while (scheduler(thread, data) == false)
		usleep(1);
	while (m_retrieve_dongle_state(thread->dongle_left) == true
		|| m_retrieve_dongle_state(thread->dongle_right) == true)
		usleep(1);
	if (thread->pos % 2 != 0)
	{
		pthread_mutex_lock(&thread->dongle_left->dongle);
		pthread_mutex_lock(&thread->dongle_right->dongle);
		m_print(thread, data, "has taken left dongle");
		m_switch_dongle_state(thread->dongle_left);
		m_print(thread, data, "has taken right dongle");
		m_switch_dongle_state(thread->dongle_right);
	}
	else
	{
		pthread_mutex_lock(&thread->dongle_right->dongle);
		pthread_mutex_lock(&thread->dongle_left->dongle);
		m_print(thread, data, "has taken right dongle");
		m_switch_dongle_state(thread->dongle_right);
		m_print(thread, data, "has taken left dongle");
		m_switch_dongle_state(thread->dongle_left);
	}
}

void	m_dongles_unlock(t_coders *thread, t_data *data)
{
	usleep(data->dongle_cooldown * 1000);
	if (thread->pos % 2 != 0)
	{
		pthread_mutex_unlock(&thread->dongle_left->dongle);
		pthread_mutex_unlock(&thread->dongle_right->dongle);
		m_switch_dongle_state(thread->dongle_left);
		m_switch_dongle_state(thread->dongle_right);
	}
	else
	{
		pthread_mutex_unlock(&thread->dongle_right->dongle);
		pthread_mutex_unlock(&thread->dongle_left->dongle);
		m_switch_dongle_state(thread->dongle_right);
		m_switch_dongle_state(thread->dongle_left);
	}
}

uint64_t	m_time(t_data *data)
{
	struct timeval	pause_timer;
	uint64_t		p_sec;
	uint64_t		p_usec;
	uint64_t		s_sec;
	uint64_t		s_usec;

	gettimeofday(&pause_timer, NULL);
	p_sec = pause_timer.tv_sec * 1000;
	p_usec = pause_timer.tv_usec / 1000;
	s_sec = data->timer_start.tv_sec * 1000;
	s_usec = data->timer_start.tv_usec / 1000;
	return ((p_sec + p_usec) - (s_sec + s_usec));
}
