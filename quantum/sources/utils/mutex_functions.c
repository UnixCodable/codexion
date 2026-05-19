/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 12:03:59 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/19 13:15:09 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

void	m_print(t_coders *thread, t_data *data, char *str)
{
	static pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&mutex);
	printf("\033[38;2;%d;%d;%dm %ld %d %s \033[0m\n", thread->pos * 51 % 120 * 2, thread->pos * 123 % 120 * 2, thread->pos * 43 % 120 * 2,
		m_time(data), thread->pos, str);
	pthread_mutex_unlock(&mutex);
}

void	m_dongles_lock(t_coders *thread, t_data *data)
{
	while (scheduler(thread, data) == false)
	{
		printf("FALSE\n");
		if (m_time(data) - thread->last_compile > data->time_to_burnout)
			m_print(thread, data, "burned out.");
	}
	pthread_mutex_lock(&thread->dongle_left->dongle);
	m_print(thread, data, "has taken left dongle");
	thread->dongle_left->is_locked = 1;
	pthread_mutex_lock(&thread->dongle_right->dongle);
	m_print(thread, data, "has taken right dongle");
	thread->dongle_right->is_locked = 1;
}

void	m_dongles_unlock(t_coders *thread, t_data *data)
{
	usleep(data->dongle_cooldown * 1000);
	pthread_mutex_unlock(&thread->dongle_left->dongle);
	thread->dongle_left->is_locked = 0;
	pthread_mutex_unlock(&thread->dongle_right->dongle);
	thread->dongle_right->is_locked = 0;
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
