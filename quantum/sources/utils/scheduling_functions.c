/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduling_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:13:07 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/29 14:59:12 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

void	s_swap(t_dongle *dongle)
{
	t_coders	*temp;

	temp = dongle->priority_queue[0];
	dongle->priority_queue[0] = dongle->priority_queue[1];
	dongle->priority_queue[1] = temp;
	return ;
}

void	s_add(t_coders *thread, t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->dongle_heap);
	if (!dongle->priority_queue[0]
		|| dongle->priority_queue[0]->pos == thread->pos)
		dongle->priority_queue[0] = thread;
	else if (!dongle->priority_queue[1])
		dongle->priority_queue[1] = thread;
	pthread_mutex_unlock(&dongle->dongle_heap);
	return ;
}

void	s_pop(t_coders *thread, t_dongle *dongle)
{
	t_coders	*temp;

	temp = NULL;
	pthread_mutex_lock(&dongle->dongle_heap);
	if (dongle->priority_queue[0]->pos == thread->pos)
	{
		temp = dongle->priority_queue[0];
		dongle->priority_queue[0] = dongle->priority_queue[1];
		dongle->priority_queue[1] = temp;
		dongle->priority_queue[1] = NULL;
	}
	else if (dongle->priority_queue[1]->pos == thread->pos)
		dongle->priority_queue[1] = NULL;
	pthread_mutex_unlock(&dongle->dongle_heap);
	return ;
}

void	s_check_edf(t_dongle *dongle, t_data *data)
{
	pthread_mutex_lock(&dongle->dongle_heap);
	if (dongle->priority_queue[1] && dongle->priority_queue[0]->last_compile
		+ data->time_to_burnout > dongle->priority_queue[1]->last_compile
		+ data->time_to_burnout)
		s_swap(dongle);
	pthread_mutex_unlock(&dongle->dongle_heap);
}

bool	scheduler(t_coders *thread, t_data *data)
{
	s_add(thread, thread->dongle_left);
	s_add(thread, thread->dongle_right);
	if (strcmp(data->scheduler, "edf") == 0)
	{
		s_check_edf(thread->dongle_left, data);
		s_check_edf(thread->dongle_right, data);
	}
	if (s_retrieve(thread->dongle_right) == thread->pos
		&& s_retrieve(thread->dongle_left) == thread->pos)
	{
		return (true);
	}
	return (false);
}
