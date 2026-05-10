/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:34:14 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/10 15:43:57 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

bool	validate_arguments(char **args)
{
	if (is_num(args[0]) == false || atoi(args[0]) < 1 || atoi(args[0]) > 250)
		return (false);
	if (is_num(args[1]) == false || atoi(args[1]) < 1 || atoi(args[1]) > 60000)
		return (false);
	if (is_num(args[2]) == false || atoi(args[2]) < 1 || atoi(args[2]) > 60000)
		return (false);
	if (is_num(args[3]) == false || atoi(args[3]) < 1 || atoi(args[3]) > 60000)
		return (false);
	if (is_num(args[4]) == false || atoi(args[4]) < 1 || atoi(args[4]) > 60000)
		return (false);
	if (is_num(args[5]) == false || atoi(args[5]) < 1 || atoi(args[5]) > 60000)
		return (false);
	if (is_num(args[6]) == false || atoi(args[6]) < 1 || atoi(args[6]) > 60000)
		return (false);
	if (strcmp(args[7], "fifo") == 0 || strcmp(args[7], "edf") == 0)
		return (true);
	return (false);
}
