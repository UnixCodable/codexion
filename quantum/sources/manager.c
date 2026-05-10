/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 01:58:43 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/10 01:57:21 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

bool	refactor(t_coders *thread)
{
	m_print(12442, thread->pos, "is refactoring...");
	usleep(thread->data->time_to_refactor * 1000);
	return (true);
}

bool	debug(t_coders *thread)
{
	m_print(12442, thread->pos, "is debugging...");
	usleep(thread->data->time_to_debug * 1000);
	return (true);
}

bool	compile(t_coders *thread)
{
	m_dongles_lock(1, thread);
	usleep(thread->data->time_to_compile * 1000);
	m_print(12442, thread->pos, "is compiling...");
	m_dongles_unlock(thread);
	return (true);
}

void	*quantum_code(void *coder)
{
	int	i;

	i = 0;
	while (i < ((t_coders *)coder)->data->number_of_compiles_required)
	{
		compile((t_coders *)coder);
		debug((t_coders *)coder);
		refactor((t_coders *)coder);
		i++;
	}
	return ((int *) 1);
}

int	start_manager(t_data *data, t_coders *coders)
{
	pthread_t			monitoring;
	int					pos;

	pos = 0;
	pthread_create(&monitoring, NULL, monitor_function, &data);
	while (pos < data->number_of_coders)
	{
		pthread_create(&coders[pos].coder, NULL, quantum_code, &coders[pos]);
		pos++;
	}
	pos = 0;
	pthread_join(monitoring, NULL);
	while (pos < data->number_of_coders)
	{
		pthread_join(coders[pos].coder, NULL);
		pos++;
	}
	return (0);
}
