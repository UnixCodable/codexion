/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:34:14 by lbordana          #+#    #+#             */
/*   Updated: 2026/04/29 20:57:52 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/codexion.h"

int	raise_error(void)
{
	fprintf(stderr, "\033[1;31mError while validating arguments.\033[0m\n");
	return (-1);
}

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
