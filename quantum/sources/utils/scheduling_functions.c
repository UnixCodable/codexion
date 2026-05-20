/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduling_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:13:07 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/20 12:50:13 by lbordana         ###   ########.fr       */
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
	if ((dongle->priority_queue[0] && dongle->priority_queue[0]->pos == thread->pos) || (dongle->priority_queue[1] && dongle->priority_queue[1]->pos == thread->pos))
		return ;
	if (!dongle->priority_queue[0])
		dongle->priority_queue[0] = thread;
	else if (!dongle->priority_queue[1])
		dongle->priority_queue[1] = thread;
	return ;
}

void	s_pop(t_coders *thread, t_dongle *dongle)
{
	if (dongle->priority_queue[0]->pos == thread->pos)
	{
		s_swap(dongle);
		dongle->priority_queue[1] = NULL;
	}
	else if (dongle->priority_queue[1]->pos == thread->pos)
		dongle->priority_queue[1] = NULL;
	return ;
}

bool	scheduler(t_coders *thread, t_data *data)
{
	pthread_mutex_lock(&thread->dongle_left->dongle_heap);
	s_add(thread, thread->dongle_left);
	s_add(thread, thread->dongle_right);
	pthread_mutex_unlock(&thread->dongle_left->dongle_heap);
	if (strcmp(data->scheduler, "fifo") == 0)
	{
		if (thread->dongle_right->priority_queue[0]->pos == thread->pos)
		{
			pthread_mutex_lock(&thread->dongle_left->dongle_heap);
			s_pop(thread, thread->dongle_left);
			s_pop(thread, thread->dongle_right);
			pthread_mutex_unlock(&thread->dongle_left->dongle_heap);
			return (true);
		}
		return (false);
	}
	if (strcmp(data->scheduler, "edf") == 0)
	{
		return (false);
	}
	return (true);
}
