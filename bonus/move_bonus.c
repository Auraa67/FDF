/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:07:16 by merazafi          #+#    #+#             */
/*   Updated: 2025/08/09 19:33:21 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	translation_x(int key, t_data *data)
{
	if (key == 65361)
	{
		data->map->offset_x -= 10;
		if (data->map->offset_x < 261)
			data->map->offset_x = 261;
	}
	if (key == 65363)
	{
		data->map->offset_x += 10;
		if (data->map->offset_x > 1441)
			data->map->offset_x = 1441;
	}
}

void	translation_y(int key, t_data *data)
{
	if (key == 65362)
	{
		data->map->offset_y -= 10;
		if (data->map->offset_y < 3)
			data->map->offset_y = 3;
	}
	if (key == 65364)
	{
		data->map->offset_y += 10;
		if (data->map->offset_y > 583)
			data->map->offset_y = 583;
	}
}

void	zoom(int key, t_data *data)
{
	if (key == 61)
	{
		data->map->zoom += 0.2;
		if (data->map->zoom > 45)
		{
			data->map->zoom = 45;
		}
	}
	if (key == 45)
	{
		data->map->zoom -= 0.4;
		if (data->map->zoom < 0.1)
		{
			data->map->zoom = 0.1;
		}
	}
}

void	scale_z(int key, t_data *data)
{
	if (key == 119)
	{
		data->map->scale_z += 0.3;
		if (data->map->scale_z >= 10)
		{
			data->map->scale_z = 10;
		}
	}
	if (key == 115)
	{
		data->map->scale_z -= 0.3;
		if (data->map->scale_z <= -10)
		{
			data->map->scale_z = -10;
		}
	}
}

void	rotate(int key, t_data *data)
{
	if (key == 114)
	{
		data->map->angle_degree += 4;
		if (data->map->angle_degree >= 360)
		{
			data->map->angle_degree = 0;
		}
	}
	if (key == 102)
	{
		data->map->angle_degree -= 4;
		if (data->map->angle_degree <= -360)
		{
			data->map->angle_degree = 0;
		}
	}
}
