/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 12:03:59 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/09 13:50:01 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

void	m_print(t_data *data, int timestamp, int thread, char *str)
{
	pthread_mutex_lock(&data->mutex);
	printf("%d %d %s", timestamp, thread, str);
	pthread_mutex_unlock(&data->mutex);
}

void	m_dongles(int timestamp, t_coders *thread)
{
	pthread_mutex_lock(thread->dongle_left);
	printf("%d %d has taken a dongle", timestamp, thread->pos);

	pthread_mutex_lock(thread->dongle_right);
	printf("%d %d has taken a dongle", timestamp, thread->pos);
}
