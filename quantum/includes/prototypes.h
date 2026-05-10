/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:43:40 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/10 00:43:27 by lbordana         ###   ########.fr       */
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
void		m_print(int timestamp, int thread, char *str);
void		m_dongles_lock(int timestamp, t_coders *thread);
void		m_dongles_unlock(t_coders *thread);



#endif
