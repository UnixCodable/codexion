/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplication.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:17:19 by lbordana          #+#    #+#             */
/*   Updated: 2026/04/29 17:28:10 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	while (s[i] != 0)
		i++;
	dup = malloc((i + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	**ft_matdup(char **s)
{
	char	**dup;
	int		i;
	int		j;

	dup = malloc(sizeof(s));
	if (!dup)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != NULL)
	{
		dup[i] = ft_strdup(s[i]);
		if (!dup[i])
			return (NULL);
		i++;
	}
	return (dup);
}
