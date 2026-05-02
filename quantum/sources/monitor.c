/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 20:55:11 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/03 01:23:33 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

void	*monitor_function(void *data)
{
	struct timeval		start_val;
	struct timeval		end_val;
	unsigned long int	monitoring_time;

	gettimeofday(&start_val, NULL);
	while (true)
	{
		gettimeofday(&end_val, NULL);
		usleep(1000);
		monitoring_time = ((end_val.tv_sec * 1000) + end_val.tv_usec / 1000) -\
((start_val.tv_sec * 1000) + start_val.tv_usec / 1000);
		printf("%ld\n", monitoring_time);
		if (((struct s_codex_data *)data)->number_of_compiles_required < 0)
			break ;
		((struct s_codex_data *)data)->number_of_compiles_required--;
	}

	return ((int)0);
}
