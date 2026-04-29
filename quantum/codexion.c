/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:27:54 by lbordana          #+#    #+#             */
/*   Updated: 2026/04/29 21:28:04 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/codexion.h"

void	quantum_manager(void)
{
	return ;
}

int	main(int ac, char **av)
{
	struct s_codex_data	data;

	av++;
	if (ac != 9 || validate_arguments(av) == false)
		return (raise_error());
	data = arguments_organizer(av);
	return (0);
}
