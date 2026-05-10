/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:46:07 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/10 15:10:59 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "codexion.h"

typedef struct s_codex_data
{
	uint8_t			number_of_coders;
	uint8_t			number_of_dongle;
	uint16_t		time_to_burnout;
	uint16_t		time_to_compile;
	uint16_t		time_to_debug;
	uint16_t		time_to_refactor;
	uint16_t		number_of_compiles_required;
	uint16_t		dongle_cooldown;
	struct timeval	timer_start;
	char			*scheduler;
}	t_data;

typedef struct s_codex_coder
{
	pthread_t			coder;
	int					pos;
	pthread_mutex_t		*dongle_left;
	pthread_mutex_t		*dongle_right;
	bool				running;
	t_data				*data;
}	t_coders;

#endif
