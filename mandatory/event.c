/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:21:02 by merazafi          #+#    #+#             */
/*   Updated: 2025/07/28 12:04:25 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_key(int key, t_map *map)
{
	if (key == 65307 || key == 17)
	{
		mlx_loop_end(map->ptr);
		mlx_destroy_image(map->ptr, map->img);
		mlx_destroy_window(map->ptr, map->win);
		mlx_destroy_display(map->ptr);
		free_matrix(map);
		free(map->ptr);
		free(map);
		exit(0);
	}
	return (0);
}

int	handle(t_map *map)
{
	mlx_loop_end(map->ptr);
	mlx_destroy_image(map->ptr, map->img);
	mlx_destroy_window(map->ptr, map->win);
	mlx_destroy_display(map->ptr);
	free_matrix(map);
	free(map->ptr);
	free(map);
	exit(0);
	return (0);
}
