/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_organizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:56:37 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/21 01:01:12 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

t_data	arguments_organizer(char **args)
{
	t_data	data;

	data = (t_data){
		.number_of_coders = atoi(args[0]),
		.number_of_dongle = atoi(args[0]),
		.time_to_burnout = atoi(args[1]),
		.time_to_compile = atoi(args[2]),
		.time_to_debug = atoi(args[3]),
		.time_to_refactor = atoi(args[4]),
		.number_of_compiles_required = atoi(args[5]),
		.dongle_cooldown = atoi(args[6]),
		.scheduler = args[7],
		.ended_coders = 0,
		.running = false
	};

	pthread_mutex_init(&data.running_mutex, NULL);
	pthread_mutex_init(&data.enders_mutex, NULL);
	gettimeofday(&data.timer_start, NULL);


	return (data);
}
