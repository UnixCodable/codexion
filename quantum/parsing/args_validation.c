/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:34:14 by lbordana          #+#    #+#             */
/*   Updated: 2026/04/29 18:54:31 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/codexion.h"

bool	validate_arguments(char **args)
{
	while ((args + 1)[0] != NULL)
	{
		if (is_number(*args) == false || atoi(*args) < 0)
			return (false);
		args++;
	}
	if (strcmp(*args, "fifo") == 0 || strcmp(*args, "edf") == 0)
		return (true);
	return (false);
}
