/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:27:54 by lbordana          #+#    #+#             */
/*   Updated: 2026/04/29 16:59:43 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	quantum_manager(void)
{
	return ;
}

int	main(int ac, char **av)
{
	av++;
	if (ac != 9 || validate_arguments(ft_matdup(av)) == false)
		return (0);

	return (1);
}
