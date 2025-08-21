/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:53:36 by merazafi          #+#    #+#             */
/*   Updated: 2025/08/10 15:00:34 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	assign_iso(t_map *map, t_var *var, int i, int j)
{
	float	x;
	float	y;
	float	z;

	x = i * map->scale_x_y;
	y = j * map->scale_x_y;
	z = map->matrix[j][i] * map->scale_z;
	map->angle_radian = map->angle_degree * PI / 180;
	map->x_rot = x;
	map->z_rot = y * sinf(map->angle_radian) + z * cosf(map->angle_radian);
	map->y_rot = y * cosf(map->angle_radian) - z * sinf(map->angle_radian);
	var->x0 = (map->x_rot - map->y_rot) * COS_30 * map->zoom + map->offset_x;
	var->y0 = (map->x_rot + map->y_rot)
		* SIN_30 * map->zoom + map->offset_y - map->z_rot;
}

static void	draw_x(t_map *map, t_var *var)
{
	float	x;
	float	y;
	float	z;

	define_color_x(map, var->i, var->j);
	x = (var->i + 1) * map->scale_x_y;
	y = var->j * map->scale_x_y;
	z = map->matrix[var->j][var->i + 1] * map->scale_z;
	map->angle_radian = map->angle_degree * PI / 180;
	map->x_rot = x;
	map->z_rot = y * sinf(map->angle_radian) + z * cosf(map->angle_radian);
	map->y_rot = y * cosf(map->angle_radian) - z * sinf(map->angle_radian);
	var->x1 = (map->x_rot - map->y_rot) * COS_30 * map->zoom + map->offset_x;
	var->y1 = (map->x_rot + map->y_rot)
		* SIN_30 * map->zoom + map->offset_y - map->z_rot;
	bresenham(map, var, (int)var->x0, (int)var->y0);
}

static void	draw_y(t_map *map, t_var *var)
{
	float	x;
	float	y;
	float	z;

	define_color_y(map, var->i, var->j);
	x = (var->i) * map->scale_x_y;
	y = (var->j + 1) * map->scale_x_y;
	z = map->matrix[var->j + 1][var->i] * map->scale_z;
	map->angle_radian = map->angle_degree * PI / 180.0f;
	map->x_rot = x;
	map->z_rot = y * sinf(map->angle_radian) + z * cosf(map->angle_radian);
	map->y_rot = y * cosf(map->angle_radian) - z * sinf(map->angle_radian);
	var->x1 = (map->x_rot - map->y_rot) * COS_30 * map->zoom + map->offset_x;
	var->y1 = (map->x_rot + map->y_rot)
		* SIN_30 * map->zoom + map->offset_y - map->z_rot;
	bresenham(map, var, (int)var->x0, (int)var->y0);
}

void	rendering_map(t_map *map, t_var *var)
{
	min_max_z(map);
	var->j = 0;
	while (var->j < map->height)
	{
		var->i = 0;
		while (var->i < map->width)
		{
			assign_iso(map, var, var->i, var->j);
			if (var->i + 1 < map->width)
			{
				draw_x(map, var);
			}
			if (var->j + 1 < map->height)
			{
				draw_y(map, var);
			}
			var->i++;
		}
		var->j++;
	}
}

void	offset_zoom(t_map *map, int win_width, int win_height)
{
	float	target_width;
	float	target_height;
	float	zoom[2];
	int		result_width;
	int		result_height;

	target_width = 500.0f;
	target_height = 500.0f;
	zoom[0] = target_width / (map->width * COS_30 * map->scale_x_y);
	zoom[1] = target_height / (map->height * SIN_30 * map->scale_x_y);
	map->zoom = ft_min(zoom[0], zoom[1]);
	result_width = (map->width) * map->zoom;
	result_height = (map->height) * map->zoom;
	map->offset_x = (win_width - result_width) / 2;
	map->offset_y = (win_height - result_height) / 2 - 200;
}
