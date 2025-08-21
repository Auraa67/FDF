/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:21:02 by merazafi          #+#    #+#             */
/*   Updated: 2025/08/09 19:38:07 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	esc(int key, t_data *data)
{
	if (key == 65307)
	{
		mlx_loop_end(data->map->ptr);
		mlx_destroy_image(data->map->ptr, data->map->img);
		mlx_destroy_window(data->map->ptr, data->map->win);
		mlx_destroy_display(data->map->ptr);
		free_matrix(data->map);
		free_color(data->map);
		free(data->map->ptr);
		free(data->var);
		free(data->map);
		exit(0);
	}
}

void	with_iso(int key, t_data *data)
{
	zoom(key, data);
	translation_x(key, data);
	translation_y(key, data);
	scale_z(key, data);
	rotate(key, data);
	mlx_destroy_image(data->map->ptr, data->map->img);
	data->map->img = mlx_new_image(data->map->ptr, WIN_X, WIN_Y);
	data->map->addr = mlx_get_data_addr(data->map->img, &data->map->bpp,
			&data->map->size_line, &data->map->endian);
	rendering_map(data->map, data->var);
	mlx_put_image_to_window(data->map->ptr, data->map->win,
		data->map->img, 0, 0);
	mlx_string_put(data->map->ptr, data->map->win,
		930, 10, 0x00FF00, "FDF BONUS");
}

void	remove_iso(int key, t_data *data)
{
	zoom(key, data);
	translation_x(key, data);
	translation_y(key, data);
	mlx_destroy_image(data->map->ptr, data->map->img);
	data->map->img = mlx_new_image(data->map->ptr, WIN_X, WIN_Y);
	data->map->addr = mlx_get_data_addr(data->map->img, &data->map->bpp,
			&data->map->size_line, &data->map->endian);
	rendering_map_without_iso(data->map, data->var);
	mlx_put_image_to_window(data->map->ptr, data->map->win,
		data->map->img, 0, 0);
	mlx_string_put(data->map->ptr, data->map->win,
		930, 10, 0x00FF00, "FDF BONUS");
}

int	handle_key(int key, t_data *data)
{
	static int	is_iso = 1;

	esc(key, data);
	if (key == 32)
	{
		if (is_iso == 1)
			is_iso = 0;
		else if (is_iso == 0)
			is_iso = 1;
	}
	if (is_iso)
	{
		with_iso(key, data);
	}
	else
	{
		remove_iso(key, data);
	}
	return (0);
}

int	handle(t_data *data)
{
	mlx_loop_end(data->map->ptr);
	mlx_destroy_image(data->map->ptr, data->map->img);
	mlx_destroy_window(data->map->ptr, data->map->win);
	mlx_destroy_display(data->map->ptr);
	free_matrix(data->map);
	free_color(data->map);
	free(data->map->ptr);
	free(data->map);
	free(data->var);
	exit(0);
	return (0);
}
