/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 01:58:43 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/03 16:13:58 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

void	*quantum_code(void *coders)
{
	(void) coders;
	while (((t_coders *)coders)[0].running == true)
	{
		compile();
		debug();
		refactor();
	}
	return ((int)0);
}

int	start_manager(struct s_codex_data *data, t_coders *coders)
{
	pthread_t			monitoring;
	struct s_codex_args	args;
	int					pos;

	pos = 0;
	args.coders = coders;
	args.data = data;
	pthread_create(&monitoring, NULL, monitor_function, &args);
	while (pos < data->number_of_coders)
	{
		pthread_create(&coders[pos].coder, NULL, quantum_code, &coders[pos]);
		pos++;
	}
	pthread_join(monitoring, NULL);
	pos = 0;
	while (pos < data->number_of_coders)
	{
		pthread_join(coders[pos].coder, NULL);
		pos++;
	}
	return (0);
}
