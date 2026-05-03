/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:46:07 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/03 16:15:26 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "codexion.h"

typedef struct s_codex_coder
{
	pthread_t	coder;
	int			pos;
	bool		*dongle_left;
	bool		*dongle_right;
	bool		running;
}	t_coders;

struct s_codex_data
{
	int			number_of_coders;
	int			number_of_dongle;
	int			time_to_burnout;
	int			time_to_compile;
	int			time_to_debug;
	int			time_to_refactor;
	int			number_of_compiles_required;
	int			dongle_cooldown;
	char		*scheduler;
};

struct s_codex_args
{
	t_coders			*coders;
	struct s_codex_data	*data;
};


#endif
