/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:43:40 by lbordana          #+#    #+#             */
/*   Updated: 2026/04/29 20:51:37 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

int						raise_error(void);
bool					validate_arguments(char **args);
bool					is_number(char *arg);
char					**ft_matdup(char **s);
char					*ft_strdup(const char *s);
struct s_codex_data		arguments_organizer(char **args);

#endif
