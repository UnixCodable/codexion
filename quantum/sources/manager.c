/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 01:58:43 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/06 17:31:47 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

bool	refactor(int thread)
{
	(void) thread;
	return (true);
}

bool	debug(int thread)
{
	(void) thread;
	return (true);
}

bool	compile(int thread)
{
	(void) thread;
	return (true);
}

void	*quantum_code(void *data)
{
	int					i = 0;
	int 				thread = ((t_data *)data)->working_thread;

	m_print((t_data *)data, thread, i, "is running.\n");
	while (i < 100)
	{
		compile(thread);
		debug(thread);
		refactor(thread);
		i++;
	}
	return ((int *) 1);
}

int	start_manager(t_data *data, t_coders *coders)
{
	pthread_t			monitoring;
	int					pos;

	pos = 0;
	data->working_thread = 0;
	pthread_create(&monitoring, NULL, monitor_function, &data);
	while (pos < data->number_of_coders)
	{
		pthread_create(&coders[pos].coder, NULL, quantum_code, data);
		data->working_thread = pos;
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

/*
	Si ajout des data à chaque coder:
	- Ok pour envoie adresse coder en cours
	-
*/
