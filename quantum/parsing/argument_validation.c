/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:34:14 by lbordana          #+#    #+#             */
/*   Updated: 2026/04/29 17:34:15 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

bool	validate_arguments(char **args)
{
	while (*args != NULL)
	{
		if (is_number(*args) == false || atoi(*args) < 0)
			return (false);
		args++;
	}
	return (true);
}
