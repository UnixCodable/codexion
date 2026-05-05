/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 01:58:43 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/05 23:50:18 by lbordana         ###   ########.fr       */
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

void	*quantum_code(void *coders)
{
	int				thread;
	int				i = 0;

	thread = ((t_coders *)coders)->pos;
	fprintf(stderr, "%d\n", thread);
	while (i < 100)
	{
		compile(thread);
		debug(thread);
		refactor(thread);
		i++;
	}
	return ((int)0);
}

int	start_manager(struct s_codex_data *data, t_coders *coders)
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
