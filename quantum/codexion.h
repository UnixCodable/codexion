/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:34:05 by lbordana          #+#    #+#             */
/*   Updated: 2026/04/29 17:32:14 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H
# define ERROR -1
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <time.h>
# include <pthread.h>
# include <string.h>

bool	validate_arguments(char **args);
char	**ft_matdup(char **s);
char	*ft_strdup(const char *s);
bool	is_number(char *arg);

struct s_codex_data
{
	int		number_of_coders;
	int		time_to_burnout;
	int		time_to_compile;
	int		time_to_debug;
	int		time_to_refactor;
	int		number_of_compiles_required;
	int		dongle_cooldown;
	char	*scheduler;
};

#endif
