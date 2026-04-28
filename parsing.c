/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:29:05 by lbordana          #+#    #+#             */
/*   Updated: 2026/04/28 15:37:24 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

bool	isnumber(char *arg)
{
	while (*arg != '\0')
	{
		if (*arg >= '0' && *arg <= '9')
			arg++;
		else
			return (false);
	}
	return (true);
}

bool	validate_arguments(char **args)
{
	while (*args != NULL)
	{
		if (isnumber(*args) == false || atoi(*args) < 0)
			return (false);
		args++;
	}
	return (true);
}
