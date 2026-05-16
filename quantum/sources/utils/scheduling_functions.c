/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduling_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:13:07 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/17 01:50:31 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

void	s_swap(t_coders *heap)
{
	return ;
}

void	s_add(t_coders *heap)
{
	return ;
}

void	s_pop(t_coders *heap)
{
	return ;
}

bool	scheduler(t_coders *thread)
{
	if (strcmp(thread->data->scheduler, "fifo") == 0)
	{
		s_add(thread->dongle_left->priority_queue);
		s_add(thread->dongle_left->priority_queue);
		return (false);
	}
	if (strcmp(thread->data->scheduler, "edf") == 0)
	{
		s_add(thread->dongle_left->priority_queue);
		s_add(thread->dongle_left->priority_queue);
		return (false);
	}
	return (true);
}
