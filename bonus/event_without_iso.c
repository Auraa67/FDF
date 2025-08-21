/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_without_iso.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:37:59 by merazafi          #+#    #+#             */
/*   Updated: 2025/08/06 12:38:15 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	assign_without_iso(t_map *map, t_var *var, int i, int j)
{
	var->x0 = (i) * map->scale_x_y * map->zoom + map->offset_x;
	var->y0 = (j) * map->scale_x_y * map->zoom
		+ map->offset_y;
}

static void	draw_x_wihtout_iso(t_map *map, t_var *var)
{
	define_color_x(map, var->i, var->j);
	var->x1 = (var->i + 1) * map->scale_x_y * map->zoom
		+ map->offset_x;
	var->y1 = (var->j) * map->scale_x_y * map->zoom
		+ map->offset_y;
	bresenham(map, var, var->x0, var->y0);
}

static void	draw_y_without_iso(t_map *map, t_var *var)
{
	define_color_y(map, var->i, var->j);
	var->x1 = (var->i) * map->scale_x_y * map->zoom
		+ map->offset_x;
	var->y1 = (var->j + 1) * map->scale_x_y * map->zoom
		+ map->offset_y;
	bresenham(map, var, var->x0, var->y0);
}

void	rendering_map_without_iso(t_map *map, t_var *var)
{
	min_max_z(map);
	var->j = 0;
	while (var->j < map->height)
	{
		var->i = 0;
		while (var->i < map->width)
		{
			assign_without_iso(map, var, var->i, var->j);
			if (var->i + 1 < map->width)
			{
				draw_x_wihtout_iso(map, var);
			}
			if (var->j + 1 < map->height)
			{
				draw_y_without_iso(map, var);
			}
			var->i++;
		}
		var->j++;
	}
}

void	offset_zoom_without_iso(t_map *map, int win_width, int win_height)
{
	float	target_width;
	float	target_height;
	float	zoom[2];
	int		result_width;
	int		result_height;

	target_width = 500.0f;
	target_height = 500.0f;
	zoom[0] = target_width / (map->width * map->scale_x_y);
	zoom[1] = target_height / (map->height * map->scale_x_y);
	map->zoom = ft_min(zoom[0], zoom[1]);
	result_width = (map->width) * map->zoom;
	result_height = (map->height) * map->zoom;
	map->offset_x = (win_width - result_width) / 2;
	map->offset_y = (win_height - result_height) / 2 - 200;
}
