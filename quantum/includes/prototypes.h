/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:43:40 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/02 02:50:27 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

bool					validate_arguments(char **args);
bool					is_number(char *arg);
char					**ft_matdup(char **s);
char					*ft_strdup(const char *s);
struct s_codex_data		arguments_organizer(char **args);
t_coders				*coders_board(struct s_codex_data *data);
int						start_manager(struct s_codex_data *data,\
	t_coders	*coders);



#endif
