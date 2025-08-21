/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:00:34 by merazafi          #+#    #+#             */
/*   Updated: 2025/07/26 12:34:38 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_max(int x, int y)
{
	if (y > x)
	{
		return (y);
	}
	return (x);
}

float	ft_min(float x, float y)
{
	if (!x || !y)
		return (0.f);
	if (y < x)
	{
		return (y);
	}
	return (x);
}

void	free_matrix(t_map *map)
{
	int	i;

	i = -1;
	if (!map || !map->matrix)
		return ;
	while (++i < map->height)
		free(map->matrix[i]);
	free(map->matrix);
	map->matrix = NULL;
}

void	free_color(t_map *map)
{
	int	i;

	i = -1;
	if (!map || !map->color_def)
		return ;
	while (++i < map->height)
		free(map->color_def[i]);
	free(map->color_def);
	map->color_def = 0;
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
