/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 15:12:07 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/11 10:33:35 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

t_coders	*coders_board(t_data *data)
{
	t_coders		*board;
	pthread_mutex_t	*dongles;
	uint8_t			pos;

	pos = 0;
	board = malloc(sizeof(t_coders) * data->number_of_coders);
	dongles = malloc(sizeof(pthread_mutex_t) * data->number_of_coders);
	if (!dongles || !board)
		return (NULL);
	while (pos < data->number_of_coders)
		pthread_mutex_init(&dongles[pos++], NULL);
	pos = 0;
	while (pos < data->number_of_coders)
	{
		board[pos].dongle_left = &dongles[pos];
		if (pos + 1 < data->number_of_coders)
			board[pos].dongle_right = &dongles[pos + 1];
		else
			board[pos].dongle_right = &dongles[0];
		board[pos].pos = pos + 1;
		board[pos].data = data;
		pos++;
	}
	return (board);
}
