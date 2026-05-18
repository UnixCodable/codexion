/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduling_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:13:07 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/19 01:07:07 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

void	s_swap(t_dongle *dongle)
{
	t_coders	*temp;
	t_coders	**heap;

	heap = dongle->priority_queue;
	temp = heap[0];
	heap[0] = heap[1];
	heap[1] = temp;
	return ;
}

void	s_add(t_coders *thread, t_dongle *dongle)
{
	t_coders	**heap;

	heap = dongle->priority_queue;
	if ((heap[0] && heap[0]->pos == thread->pos) || (heap[1] && heap[1]->pos == thread->pos))
		return ;
	if (!heap[0])
		heap[0] = thread;
	else if (!heap[1])
		heap[1] = thread;
	return ;
}

void	s_pop(t_coders *thread, t_dongle *dongle)
{
	t_coders	**heap;

	heap = dongle->priority_queue;
	if (heap[0]->pos == thread->pos)
	{
		s_swap(dongle);
		heap[1] = NULL;
	}
	else if (heap[1]->pos == thread->pos)
		heap[1] = NULL;
	return ;
}

bool	scheduler(t_coders *thread, t_data *data)
{
	while (thread->dongle_right->is_locked == 1 || thread->dongle_left->is_locked == 1)
		;
	if (strcmp(data->scheduler, "fifo") == 0)
	{
		s_add(thread, thread->dongle_left);
		s_add(thread, thread->dongle_right);
		if (thread->dongle_right->priority_queue[0]->pos == thread->pos)
		{
			s_pop(thread, thread->dongle_left);
			s_pop(thread, thread->dongle_right);
			return (true);
		}
		return (false);
	}
	if (strcmp(data->scheduler, "edf") == 0)
	{
		s_add(thread, thread->dongle_left);
		s_add(thread, thread->dongle_right);
		return (false);
	}
	return (true);
}
