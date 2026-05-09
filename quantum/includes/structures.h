/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:46:07 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/09 12:58:40 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "codexion.h"

typedef struct s_codex_data
{
	int				number_of_coders;
	int				number_of_dongle;
	int				time_to_burnout;
	int				time_to_compile;
	int				time_to_debug;
	int				time_to_refactor;
	int				number_of_compiles_required;
	int				dongle_cooldown;
	char			*scheduler;
	pthread_mutex_t	mutex;
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
