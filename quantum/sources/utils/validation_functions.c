/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:26:44 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/10 15:04:14 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

bool	is_num(char *arg)
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
