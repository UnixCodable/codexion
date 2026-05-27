/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:17:28 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/28 00:59:34 by lbordana         ###   ########.fr       */
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
		.mute = false,
		.running = true
	};
	pthread_mutex_init(&data.running_mutex, NULL);
	pthread_mutex_init(&data.enders_mutex, NULL);
	pthread_mutex_init(&data.print_mutex, NULL);
	gettimeofday(&data.timer_start, NULL);
	return (data);
}

bool	validate_arguments(char **args)
{
	if (is_num(args[0]) == false || atoi(args[0]) < 1 || atoi(args[0]) > 250)
		return (false);
	if (is_num(args[1]) == false || atoi(args[1]) < 0 || atoi(args[1]) > 60000)
		return (false);
	if (is_num(args[2]) == false || atoi(args[2]) < 0 || atoi(args[2]) > 60000)
		return (false);
	if (is_num(args[3]) == false || atoi(args[3]) < 0 || atoi(args[3]) > 60000)
		return (false);
	if (is_num(args[4]) == false || atoi(args[4]) < 0 || atoi(args[4]) > 60000)
		return (false);
	if (is_num(args[5]) == false || atoi(args[5]) < 0 || atoi(args[5]) > 60000)
		return (false);
	if (is_num(args[6]) == false || atoi(args[6]) < 0 || atoi(args[6]) > 60000)
		return (false);
	if (strcmp(args[7], "fifo") == 0 || strcmp(args[7], "edf") == 0)
		return (true);
	return (false);
}
