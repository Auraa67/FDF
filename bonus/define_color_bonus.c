/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_color_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:12:09 by merazafi          #+#    #+#             */
/*   Updated: 2025/08/05 19:15:47 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	min_max_z(t_map *map)
{
	int	i;
	int	j;

	map->z_min = map->matrix[0][0];
	map->z_max = map->matrix[0][0];
	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if (map->matrix[j][i] < map->z_min)
			{
				map->z_min = map->matrix[j][i];
			}
			if (map->matrix[j][i] > map->z_max)
			{
				map->z_max = map->matrix[j][i];
			}
			i++;
		}
		j++;
	}
}

int	interpolate_color(int color1, int color2, float t)
{
	int	r;
	int	g;
	int	b;

	r = ((1 - t) * ((color1 >> 16) & 0xFF)) + (t * ((color2 >> 16) & 0xFF));
	g = ((1 - t) * ((color1 >> 8) & 0xFF)) + (t * ((color2 >> 8) & 0xFF));
	b = ((1 - t) * ((color1) & 0xFF)) + (t * ((color2) & 0xFF));
	return (r << 16 | g << 8 | b);
}

void	define_color_x(t_map *map, int i, int j)
{
	map->z_actual = map->matrix[j][i];
	map->z_x_y = map->matrix[j][i + 1];
	if (map->color_def[j][i] != NO_COLOR
			&& map->color_def[j][i + 1] != NO_COLOR)
	{
		map->color1 = map->color_def[j][i];
		map->color2 = map->color_def[j][i + 1];
		return ;
	}
	else if (map->z_max == map->z_min)
	{
		map->color1 = COLOR_LOW;
		map->color2 = COLOR_LOW;
		return ;
	}
	else if (map->color_def[j][i] != NO_COLOR
		|| map->color_def[j][i + 1] != NO_COLOR)
	{
		if (map_color_def_with_no_color(map, i, j, "color_x"))
			return ;
	}
	define_map_color_without_color(map, "color1");
	define_map_color_without_color(map, "color2");
}

void	define_color_y(t_map *map, int i, int j)
{
	map->z_actual = map->matrix[j][i];
	map->z_x_y = map->matrix[j + 1][i];
	if (map->color_def[j][i] != NO_COLOR
			&& map->color_def[j + 1][i] != NO_COLOR)
	{
		map->color1 = map->color_def[j][i];
		map->color2 = map->color_def[j + 1][i];
		return ;
	}
	else if (map->z_max == map->z_min)
	{
		map->color1 = COLOR_LOW;
		map->color2 = COLOR_LOW;
		return ;
	}
	else if (map->color_def[j][i] != NO_COLOR
		|| map->color_def[j + 1][i] != NO_COLOR)
	{
		if (map_color_def_with_no_color(map, i, j, "color_y"))
			return ;
	}
	define_map_color_without_color(map, "color1");
	define_map_color_without_color(map, "color2");
}
