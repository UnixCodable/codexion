/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:43:40 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/06 16:08:55 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

bool		validate_arguments(char **args);
bool		is_number(char *arg);
char		**ft_matdup(char **s);
char		*ft_strdup(const char *s);
t_data		arguments_organizer(char **args);
t_coders	*coders_board(t_data *data);
int			start_manager(t_data *data, t_coders *coders);
void		*monitor_function(void *data);
void		m_print(t_data *data, int timestamp, int thread, char *str);



#endif
