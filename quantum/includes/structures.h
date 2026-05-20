/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:46:07 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/20 12:13:46 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "codexion.h"

typedef struct s_codex_data		t_data;
typedef struct s_codex_coder	t_coders;
typedef struct s_codex_dongle	t_dongle;
typedef struct s_codex_zip		t_zip;

struct s_codex_data
{
	uint8_t			number_of_coders;
	uint8_t			number_of_dongle;
	uint8_t			ended_coders;
	uint16_t		time_to_burnout;
	uint16_t		time_to_compile;
	uint16_t		time_to_debug;
	uint16_t		time_to_refactor;
	uint16_t		number_of_compiles_required;
	uint16_t		dongle_cooldown;
	bool			running;
	struct timeval	timer_start;
	char			*scheduler;
	t_coders		**heap;
};

struct s_codex_coder
{
	pthread_t			coder;
	uint8_t				pos;
	t_dongle			*dongle_left;
	t_dongle			*dongle_right;
	uint64_t			last_compile;
};

struct s_codex_dongle
{
	pthread_mutex_t		dongle;
	pthread_mutex_t		dongle_heap;
	t_coders			*priority_queue[2];
};

struct s_codex_zip
{
	t_data		*data;
	t_coders	*coders;
};

#endif
