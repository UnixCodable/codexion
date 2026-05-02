/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_organizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:56:37 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/02 02:28:21 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

struct s_codex_data	arguments_organizer(char **args)
{
	struct s_codex_data	data;

	data.number_of_coders = atoi(args[0]);
	data.number_of_dongle = atoi(args[0]);
	data.time_to_burnout = atoi(args[1]);
	data.time_to_compile = atoi(args[2]);
	data.time_to_debug = atoi(args[3]);
	data.time_to_refactor = atoi(args[4]);
	data.number_of_compiles_required = atoi(args[5]);
	data.dongle_cooldown = atoi(args[6]);
	data.scheduler = args[7];

	return (data);
}
