/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 01:58:43 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/02 03:24:40 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

void	*quantum_code(void *coders)
{
	printf("Hello from %d\n", ((t_coders *)coders)[0].pos);
	return ((int)0);
}

int	start_manager(struct s_codex_data *data, t_coders *coders)
{
	int			pos;

	pos = 0;
	while (pos < data->number_of_coders)
	{
		pthread_create(&coders[pos].coder, NULL, quantum_code, &coders[pos]);
		pthread_join(coders[pos].coder, NULL);
		pos++;
	}
	return (0);
}
