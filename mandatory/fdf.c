/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:23:00 by merazafi          #+#    #+#             */
/*   Updated: 2025/08/09 18:47:13 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_window(t_map *map, t_var *var)
{
	map->ptr = mlx_init();
	if (!map->ptr)
	{
		free_matrix(map);
		free_color(map);
		free(map);
		free(var);
		print_error("Error\n");
	}
	map->win = mlx_new_window(map->ptr, WIN_X, WIN_Y, "FDF");
	map->img = mlx_new_image(map->ptr, WIN_X, WIN_Y);
	map->addr = mlx_get_data_addr(map->img, &map->bpp,
			&map->size_line, &map->endian);
	offset_zoom(map, WIN_X, WIN_Y);
	mlx_key_hook(map->win, handle_key, map);
	mlx_hook(map->win, 17, 0, handle, map);
	rendering_map(map, var);
	free_color(map);
	free(var);
	mlx_put_image_to_window(map->ptr, map->win, map->img, 0, 0);
	mlx_string_put(map->ptr, map->win, 920, 10, 0x00FF00, "FDF MANDATORY");
	mlx_loop(map->ptr);
}

int	main(int argc, char *argv[])
{
	t_map	*map;
	t_var	*var;

	check_file(argv[1], argc);
	directory_file(argv[1]);
	map = NULL;
	var = NULL;
	init_struct(&map);
	init_height_and_width(argv[1], &map);
	if (map->height == 1 && map->width == 1)
	{
		free(map);
		print_error("Too small, please change the map\n");
	}
	init_struct_pt2(&var, &map);
	parsing(argv[1], map, var);
	init_window(map, var);
	return (0);
}
