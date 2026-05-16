/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:43:40 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/16 19:12:16 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

bool				validate_arguments(char **args);
bool				is_num(char *arg);
bool				scheduler(t_coders *thread);
t_data				arguments_organizer(char **args);
t_coders			*coders_board(t_data *data);
int					start_manager(t_data *data, t_coders *coders);
void				*monitor_function(void *data);
void				m_print(t_coders *thread, char *str);
void				m_dongles_lock(t_coders *thread);
void				m_dongles_unlock(t_coders *thread);
unsigned long int	m_time(t_data *data);



#endif
