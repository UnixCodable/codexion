/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:26:44 by lbordana          #+#    #+#             */
/*   Updated: 2026/04/30 14:05:02 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

bool	is_number(char *arg)
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
