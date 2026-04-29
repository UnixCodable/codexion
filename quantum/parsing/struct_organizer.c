/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_organizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:56:37 by lbordana          #+#    #+#             */
/*   Updated: 2026/04/30 01:35:10 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/codexion.h"

t_codex_list	*coder_creation(void)
{
	t_codex_list	*coder;
	static int		pos;

	pos = 1;
	coder = malloc(sizeof(t_codex_list));
	if (!coder)
		return (NULL);
	coder->position = pos;
	coder->next = NULL;
	coder->previous = NULL;
	return (coder);
}

t_codex_list	*coders_board(struct s_codex_data *data)
{
	t_codex_list	*coders;
	t_codex_list	*board;

	coders = coder_creation();
	board = coders;
	if (data->number_of_coders == 1)
		return (board);
	while (coders->position != data->number_of_coders)
	{
		coders->next = coder_creation();
		coders->next->previous = coders;
		coders = coders->next;
	}
	coders->next = board;
	board->previous = coders;
	return (board);
}

struct s_codex_data	arguments_organizer(char **args)
{
	struct s_codex_data	data;

	data.number_of_coders = atoi(args[0]);
	data.number_of_dongle = atoi(args[0]);
	data.time_to_burnout = atoi(args[1]);
	data.time_to_compile = atoi(args[2]);
	data.time_to_debug = atoi(args[3]);
	data.time_to_refactor = atoi(args[4]);
	data.number_of_compiles_required = atoi(args[5]);
	data.dongle_cooldown = atoi(args[6]);
	data.scheduler = args[7];

	return (data);
}
