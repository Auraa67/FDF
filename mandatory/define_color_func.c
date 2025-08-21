/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_color_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:10:49 by merazafi          #+#    #+#             */
/*   Updated: 2025/08/05 19:40:35 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	define_map_color_without_color(t_map *map, char *type)
{
	float	res;

	res = 0;
	if (ft_strcmp(type, "color1") == 0)
	{
		res = (float)(map->z_actual - map->z_min) / (map->z_max - map->z_min);
		map->t1 = res;
		map->color1 = interpolate_color(COLOR_LOW, COLOR_HIGH, map->t1);
	}
	else if (ft_strcmp(type, "color2") == 0)
	{
		res = (float)(map->z_x_y - map->z_min) / (map->z_max - map->z_min);
		map->t2 = res;
		map->color2 = interpolate_color(COLOR_LOW, COLOR_HIGH, map->t2);
	}
}

void	map_def_color_equals_with_color(t_map *map, int i, int j, char *type)
{
	map->color1 = map->color_def[j][i];
	if (ft_strcmp(type, "color_x") == 0)
	{
		define_map_color_without_color(map, "color2");
	}
	if (ft_strcmp(type, "color_y") == 0)
	{
		define_map_color_without_color(map, "color2");
	}
}

void	map_def_color_equals_no_color(t_map *map, int i, int j, char *type)
{
	define_map_color_without_color(map, "color1");
	if (ft_strcmp(type, "color_x") == 0)
	{
		if (i > 0 && map->color_def[j][i - 1] != NO_COLOR)
		{
			map->color2 = map->color_def[j][i - 1];
		}
		else if (map->color_def[j][i + 1] != NO_COLOR)
		{
			map->color2 = map->color_def[j][i + 1];
		}
	}
	else if (ft_strcmp(type, "color_y") == 0)
	{
		if (j > 0 && map->color_def[j - 1][i] != NO_COLOR)
		{
			map->color2 = map->color_def[j - 1][i];
		}
		else if (map->color_def[j + 1][i] != NO_COLOR)
		{
			map->color2 = map->color_def[j + 1][i];
		}
	}
}

int	map_color_def_with_no_color(t_map *map, int i, int j, char *type)
{
	if (map->color_def[j][i] != NO_COLOR)
	{
		map_def_color_equals_with_color(map, i, j, type);
		return (1);
	}
	else if (map->color_def[j][i] == NO_COLOR)
	{
		map_def_color_equals_no_color(map, i, j, type);
		return (1);
	}
	return (0);
}
