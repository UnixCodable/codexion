/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:27:54 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/02 03:24:00 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

int	raise_error(int error_code)
{
	if (error_code == 1)
		fprintf(stderr, "\033[1;31mError while validating arguments.\033[0m\n");
	if (error_code == 2)
		fprintf(stderr, "\033[1;31mError while allocating memory.\033[0m\n");
	return (-1);
}

int	main(int ac, char **av)
{
	struct s_codex_data	data;
	t_coders			*board;

	av++;
	if (ac != 9 || validate_arguments(av) == false)
		return (raise_error(1));
	data = arguments_organizer(av);
	board = coders_board(&data);
	if (!board)
		return (raise_error(2));
	start_manager(&data, board);
	free(board[0].dongle_left);
	free(board);
	return (EXIT_SUCCESS);
}
