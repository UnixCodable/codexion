/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 15:12:07 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/29 11:19:18 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

t_dongle	*dongle_init(t_data *data)
{
	t_dongle	*dongles;
	uint8_t		pos;

	pos = 0;
	dongles = malloc(sizeof(t_dongle) * data->number_of_coders);
	if (!dongles)
		return (NULL);
	while (pos < data->number_of_coders)
	{
		pthread_mutex_init(&dongles[pos].dongle, NULL);
		pthread_mutex_init(&dongles[pos].dongle_heap, NULL);
		pthread_mutex_init(&dongles[pos].dongle_state, NULL);
		dongles[pos].priority_queue[0] = NULL;
		dongles[pos].priority_queue[1] = NULL;
		dongles[pos++].is_locked = false;
	}
	return (dongles);
}

t_coders	*coders_board(t_data *data)
{
	t_coders	*board;
	t_dongle	*dongles;
	uint8_t		pos;

	pos = 0;
	board = malloc(sizeof(t_coders) * data->number_of_coders);
	dongles = dongle_init(data);
	if (!dongles || !board)
		return (NULL);
	while (pos < data->number_of_coders)
	{
		board[pos].dongle_left = &dongles[pos];
		if (pos + 1 < data->number_of_coders)
			board[pos].dongle_right = &dongles[pos + 1];
		else
			board[pos].dongle_right = &dongles[0];
		board[pos].pos = pos + 1;
		board[pos].last_compile = m_time(data);
		pthread_mutex_init(&board[pos].time_mutex, NULL);
		pos++;
	}
	return (board);
}
