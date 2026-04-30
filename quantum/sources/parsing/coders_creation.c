/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 15:12:07 by lbordana          #+#    #+#             */
/*   Updated: 2026/04/30 16:13:44 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

t_coders	*coders_board(struct s_codex_data *data)
{
	t_coders	*board;
	int			pos;

	pos = 0;
	board = malloc(sizeof(t_coders) * data->number_of_coders);
	while (pos < data->number_of_coders)
	{
		board[pos].dongle_left = NULL;
		board[pos].dongle_right = NULL;
		pos++;
		board[pos].pos = pos;
	}
	return (board);
}
