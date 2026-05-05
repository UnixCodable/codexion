/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 15:12:07 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/05 16:07:18 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

t_coders	*coders_board(struct s_codex_data *data)
{
	t_coders	*board;
	bool		*dongles;
	int			pos;

	pos = 0;
	board = malloc(sizeof(t_coders) * data->number_of_coders);
	dongles = malloc(sizeof(bool) * data->number_of_coders);
	if (!dongles || !board)
		return (NULL);
	while (pos < data->number_of_coders)
		dongles[pos++] = false;
	pos = 0;
	while (pos < data->number_of_coders)
	{
		board[pos].dongle_left = &dongles[pos];
		board[pos].dongle_right = &dongles[pos + 1];
		board[pos].pos = pos + 1;
		pos++;
	}
	return (board);
}
