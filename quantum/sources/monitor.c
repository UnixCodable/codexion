/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 20:55:11 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/05 18:15:34 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

void	*monitor_function(void *data)
{
	struct timeval		start_val;
	struct timeval		end_val;
	unsigned long int	monitoring_time;
	int					i = 1000;

	(void) data;
	gettimeofday(&start_val, NULL);
	while (true)
	{
		gettimeofday(&end_val, NULL);
		monitoring_time = ((end_val.tv_sec * 1000) + end_val.tv_usec / 1000) -\
((start_val.tv_sec * 1000) + start_val.tv_usec / 1000);
		(void) monitoring_time;
		if (i < 0)
			break ;
		i--;
	}
	return ((int)0);
}
