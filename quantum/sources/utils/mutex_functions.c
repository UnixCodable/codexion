/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 12:03:59 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/29 12:19:10 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

void	m_print(t_coders *thread, t_data *data, char *str, bool burnout)
{
	pthread_mutex_lock(&data->print_mutex);
	if (data->mute == false || burnout == true)
		printf("\033[1;38;2;%lu;%lu;%lum %ld %u %s \033[0m\n",
			(uint64_t)thread->dongle_left % 255,
			(uint64_t)thread->dongle_right % 255,
			(uint64_t) &(thread->pos) % 255, m_time(data), thread->pos, str);
	pthread_mutex_unlock(&data->print_mutex);
}

void	m_dongles_lock(t_coders *thread, t_data *data)
{
	while (scheduler(thread, data) == false)
		usleep(1);
	if (thread->pos % 2 == 1)
	{
		pthread_mutex_lock(&thread->dongle_left->dongle);
		pthread_mutex_lock(&thread->dongle_right->dongle);
		while (m_retrieve_dongle_state(thread->dongle_left, data) == true
			|| m_retrieve_dongle_state(thread->dongle_right, data) == true)
			usleep(1);
	}
	else
	{
		pthread_mutex_lock(&thread->dongle_right->dongle);
		pthread_mutex_lock(&thread->dongle_left->dongle);
		while (m_retrieve_dongle_state(thread->dongle_left, data) == true
			|| m_retrieve_dongle_state(thread->dongle_right, data) == true)
			usleep(1);
	}
	m_switch_dongle_state(thread->dongle_left);
	m_print(thread, data, "has taken left dongle", false);
	m_switch_dongle_state(thread->dongle_right);
	m_print(thread, data, "has taken right dongle", false);
}

void	m_dongles_unlock(t_coders *thread, t_data *data)
{
	pthread_mutex_unlock(&thread->dongle_right->dongle);
	pthread_mutex_unlock(&thread->dongle_left->dongle);
	pthread_mutex_lock(&thread->dongle_left->dongle_state);
	thread->dongle_left->last_used = m_time(data);
	pthread_mutex_unlock(&thread->dongle_left->dongle_state);
	pthread_mutex_lock(&thread->dongle_right->dongle_state);
	thread->dongle_right->last_used = m_time(data);
	pthread_mutex_unlock(&thread->dongle_right->dongle_state);
	m_switch_dongle_state(thread->dongle_right);
	m_switch_dongle_state(thread->dongle_left);
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
