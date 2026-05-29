/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:43:40 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/29 12:29:25 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

bool		validate_arguments(char **args);
bool		is_num(char *arg);
bool		scheduler(t_coders *thread, t_data *data);
t_data		arguments_organizer(char **args);
t_coders	*coders_board(t_data *data);
bool		start_manager(t_data *data, t_coders *coders);
void		*monitor_function(void *data);
void		m_print(t_coders *thread, t_data *data, char *str, bool burnout);
void		m_dongles_lock(t_coders *thread, t_data *data);
void		m_dongles_unlock(t_coders *thread, t_data *data);
uint64_t	m_time(t_data *data);
void		m_switch_running_state(t_data *data);
bool		m_retrieve_running_state(t_data *data);
bool		m_retrieve_dongle_state(t_dongle *dongle, t_data *data);
int			s_retrieve(t_dongle *dongle);

#endif
