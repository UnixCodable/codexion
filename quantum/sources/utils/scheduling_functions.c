/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduling_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:13:07 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/27 08:36:47 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

int	s_retrieve(t_dongle *dongle)
{
	int	coder_pos;

	pthread_mutex_lock(&dongle->dongle_heap);
	coder_pos = dongle->priority_queue[0]->pos;
	pthread_mutex_unlock(&dongle->dongle_heap);
	return (coder_pos);
}

void	s_swap(t_dongle *dongle)
{
	t_coders	*temp;

	pthread_mutex_lock(&dongle->dongle_heap);
	temp = dongle->priority_queue[0];
	dongle->priority_queue[0] = dongle->priority_queue[1];
	dongle->priority_queue[1] = temp;
	pthread_mutex_unlock(&dongle->dongle_heap);
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

bool	scheduler(t_coders *thread, t_data *data)
{
	s_add(thread, thread->dongle_left);
	s_add(thread, thread->dongle_right);
	// fprintf(stderr, "%d (left): [%d, %d]\n", thread->pos, thread->dongle_left->priority_queue[0] ? thread->dongle_left->priority_queue[0]->pos : -1, thread->dongle_left->priority_queue[1] ? thread->dongle_left->priority_queue[1]->pos : -1);
	// fprintf(stderr, "%d (right): [%d, %d]\n", thread->pos, thread->dongle_right->priority_queue[0] ? thread->dongle_right->priority_queue[0]->pos : -1, thread->dongle_right->priority_queue[1] ? thread->dongle_right->priority_queue[1]->pos : -1);
	if (strcmp(data->scheduler, "edf") == 0)
	{
		if (thread->dongle_left->priority_queue[1]
			&& thread->dongle_left->priority_queue[0]->last_compile
			+ data->time_to_burnout
			> thread->dongle_left->priority_queue[1]->last_compile
			+ data->time_to_burnout)
			s_swap(thread->dongle_left);
		if (thread->dongle_right->priority_queue[1]
			&& thread->dongle_right->priority_queue[0]->last_compile
			+ data->time_to_burnout
			> thread->dongle_right->priority_queue[1]->last_compile
			+ data->time_to_burnout)
			s_swap(thread->dongle_right);
	}
	if (s_retrieve(thread->dongle_right) == thread->pos
		&& s_retrieve(thread->dongle_left) == thread->pos)
	{
		s_pop(thread, thread->dongle_right);
		s_pop(thread, thread->dongle_left);
		return (true);
	}
	return (false);
}
