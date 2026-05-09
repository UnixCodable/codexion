/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 15:12:07 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/09 14:18:10 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/codexion.h"

t_coders	*coders_board(t_data *data)
{
	t_coders		*board;
	pthread_mutex_t	*dongles;
	int				pos;

	pos = 0;
	board = malloc(sizeof(t_coders) * data->number_of_coders);
	dongles = malloc(sizeof(pthread_mutex_t) * data->number_of_coders);
	if (!dongles || !board)
		return (NULL);
	while (pos < data->number_of_coders)
	{
		pthread_mutex_init(&dongles[pos], NULL);
		pos++;
	}
	pos = 0;
	while (pos < data->number_of_coders)
	{
		board[pos].dongle_left = &dongles[pos];
		board[pos].dongle_right = &dongles[pos + 1];
		board[pos].pos = pos + 1;
		board[pos].data = data;
		pos++;
	}
	return (board);
}
