/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:23:00 by merazafi          #+#    #+#             */
/*   Updated: 2025/08/09 18:55:37 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	verif_w_h(t_map *map, int fd, int check)
{
	if (ft_strcmp(map->valid, "no") == 0 && check == 1)
	{
		free_close_err(map, fd, "Invalid width\n");
	}
	if (map->height <= 0)
	{
		free_close_err(map, fd, "Too small. Change the map\n");
	}
}

static void	init_window(t_data *data)
{
	data->map->ptr = mlx_init();
	if (!data->map->ptr)
	{
		free_matrix(data->map);
		free_color(data->map);
		free(data->map);
		free(data->var);
		print_error("Error\n");
	}
	data->map->win = mlx_new_window(data->map->ptr, WIN_X, WIN_Y, "FDF");
	data->map->img = mlx_new_image(data->map->ptr, 3000, 3000);
	data->map->addr = mlx_get_data_addr(data->map->img, &data->map->bpp,
			&data->map->size_line, &data->map->endian);
	offset_zoom(data->map, WIN_X, WIN_Y);
	mlx_key_hook(data->map->win, handle_key, data);
	mlx_hook(data->map->win, 17, 0, handle, data);
	rendering_map(data->map, data->var);
	mlx_put_image_to_window(data->map->ptr, data->map->win,
		data->map->img, 0, 0);
	mlx_string_put(data->map->ptr, data->map->win, 930, 10,
		0x00FF00, "FDF BONUS");
	mlx_loop(data->map->ptr);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	data.map = NULL;
	data.var = NULL;
	check_file(argv[1], argc);
	directory_file(argv[1]);
	init_struct_map(&data.map, argv[1]);
	init_struct_var(&data.var);
	if (data.map->height == 1 && data.map->width == 1)
	{
		free(data.map);
		free(data.var);
		print_error("Too small, please change the map\n");
	}
	parsing(argv[1], data.map, data.var);
	init_window(&data);
	return (0);
}
