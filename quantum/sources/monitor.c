/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 20:55:11 by lbordana          #+#    #+#             */
/*   Updated: 2026/05/16 15:52:37 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

void	*monitor_function(void *data_addr)
{
	t_data	*data;

	data = (t_data *)data_addr;
	(void)data;
	return ((bool *)true);
}
