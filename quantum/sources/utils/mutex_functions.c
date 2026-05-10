/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 12:03:59 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/10 11:28:04 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

void	m_print(t_coders *thread, char *str)
{
	static pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&mutex);
	printf("%ld %d %s\n", m_time(thread->data), thread->pos, str);
	pthread_mutex_unlock(&mutex);
}

void	m_dongles_lock(t_coders *thread)
{
	pthread_mutex_lock(thread->dongle_right);
	pthread_mutex_lock(thread->dongle_left);
	printf("%ld %d has taken a dongle\n", m_time(thread->data), thread->pos);
	printf("%ld %d has taken a dongle\n", m_time(thread->data), thread->pos);
}

void	m_dongles_unlock(t_coders *thread)
{
	usleep(thread->data->dongle_cooldown * 1000);
	pthread_mutex_unlock(thread->dongle_left);
	pthread_mutex_unlock(thread->dongle_right);
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
