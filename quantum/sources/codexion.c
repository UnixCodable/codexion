/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:27:54 by lbordana          #+#    #+#             */
/*   Updated: 2026/04/30 14:25:52 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

void	*print_things(void	*data)
{
	printf("thing\n");
	(void) data;
	pthread_exit(EXIT_SUCCESS);
}

void	quantum_manager(void)
{
	pthread_t	client;

	pthread_create(&client, NULL, print_things, NULL);
	pthread_join(client, NULL);
	return ;
}

int	raise_error(void)
{
	fprintf(stderr, "\033[1;31mError while validating arguments.\033[0m\n");
	return (-1);
}

int	main(int ac, char **av)
{
	struct s_codex_data	data;

	av++;
	if (ac != 9 || validate_arguments(av) == false)
		return (raise_error());
	data = arguments_organizer(av);
	(void) data;
	quantum_manager();
	return (EXIT_SUCCESS);
}
