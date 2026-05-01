/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:34:14 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/01 00:11:01 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

bool	validate_arguments(char **args)
{
	while ((args + 1)[0] != NULL)
	{
		if (is_number(*args) == false || atoi(*args) < 1)
			return (false);
		args++;
	}
	if (strcmp(*args, "fifo") == 0 || strcmp(*args, "edf") == 0)
		return (true);
	return (false);
}
