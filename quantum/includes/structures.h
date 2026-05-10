/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:46:07 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/10 11:50:05 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "codexion.h"

typedef struct s_codex_data
{
	uint8_t			number_of_coders;
	uint8_t			number_of_dongle;
	unsigned int	time_to_burnout;
	unsigned int	time_to_compile;
	unsigned int	time_to_debug;
	unsigned int	time_to_refactor;
	unsigned int	number_of_compiles_required;
	unsigned int	dongle_cooldown;
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
