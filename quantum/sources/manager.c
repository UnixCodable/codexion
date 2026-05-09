/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 01:58:43 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/09 14:29:09 by lbordana         ###   ########.fr       */
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

void	*quantum_code(void *coder)
{
	int					i;

	i = 0;
	while (i < 10)
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
