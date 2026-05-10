/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 12:03:59 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/10 01:48:24 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

void	m_print(int timestamp, int thread, char *str)
{
	static pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&mutex);
	printf("%d %d %s\n", timestamp, thread, str);
	pthread_mutex_unlock(&mutex);
}

void	m_dongles_lock(int timestamp, t_coders *thread)
{
	// static pthread_cond_t	cond = PTHREAD_COND_INITIALIZER;

	(void) timestamp;
	pthread_mutex_lock(thread->dongle_right);
	pthread_mutex_lock(thread->dongle_left);
	printf("%d %lld has taken a right dongle\n", thread->pos, (long long int)thread->dongle_right);
	printf("%d %lld has taken a left dongle\n", thread->pos, (long long int)thread->dongle_left);
}

void	m_dongles_unlock(t_coders *thread)
{
	usleep(thread->data->dongle_cooldown * 1000);
	pthread_mutex_unlock(thread->dongle_left);
	pthread_mutex_unlock(thread->dongle_right);
}
