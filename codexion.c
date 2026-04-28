/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:27:54 by lbordana          #+#    #+#             */
/*   Updated: 2026/04/28 16:15:27 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int ac, char **av)
{
	if (ac != 9 || validate_arguments(av + 1) == false)
	{
		printf("Here");
		return (0);
	}

	return (1);
}
