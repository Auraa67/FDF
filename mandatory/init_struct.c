/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:14:46 by merazafi          #+#    #+#             */
/*   Updated: 2025/08/10 14:31:00 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	verif_w_h(t_map *map, int fd, int check)
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

static void	assign_w_h(char **line, int *check, t_map **map, int *first_width)
{
	if (*line[0] == '\n')
		(*map)->valid = "no";
	(*map)->width = count_nbr(*line);
	if ((*check) == 0)
		(*first_width) = (*map)->width;
	if ((*check) == 1 && (*first_width) != (*map)->width)
		(*map)->valid = "no";
	(*check) = 1;
	(*map)->height++;
}

void	init_height_and_width(char *text, t_map **map)
{
	int		fd;
	char	*line;
	int		check;
	int		first_width;

	check = 0;
	fd = open(text, O_RDONLY);
	if (fd == -1)
	{
		free(*map);
		print_error("Error fd\n");
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		assign_w_h(&line, &check, map, &first_width);
		free(line);
	}
	verif_w_h((*map), fd, check);
	close(fd);
}

void	init_struct_pt2(t_var **var, t_map **map)
{
	(*var) = malloc(sizeof(t_var));
	if (!*var)
		return ;
	(*var)->i = 0;
	(*var)->j = 0;
	(*var)->x0 = 0;
	(*var)->x1 = 0;
	(*var)->y0 = 0;
	(*var)->y1 = 0;
	(*var)->d_x = 0;
	(*var)->d_y = 0;
	(*var)->s_x = 0;
	(*var)->s_y = 0;
	(*var)->steps = 0;
	(*var)->err1 = 0;
	(*var)->t = 0;
	(*var)->fd = -1;
	(*var)->line = NULL;
	(*var)->check = 0;
	(*var)->color_for_one = NULL;
	(*var)->i_lgn = NULL;
	(*map)->color1 = 0;
	(*map)->color2 = 0;
	(*map)->color_z = 0;
	(*map)->color_def = 0;
}

void	init_struct(t_map **map)
{
	(*map) = malloc(sizeof(t_map));
	if (!*map)
		return ;
	(*map)->i = 0;
	(*map)->ptr = NULL;
	(*map)->win = NULL;
	(*map)->img = NULL;
	(*map)->addr = NULL;
	(*map)->valid = "yes";
	(*map)->bpp = 0;
	(*map)->size_line = 0;
	(*map)->endian = 0;
	(*map)->width = 0;
	(*map)->height = 0;
	(*map)->zoom = 0.1f;
	(*map)->offset_x = 0.0f;
	(*map)->offset_y = 0.0f;
	(*map)->matrix = 0;
	(*map)->z_min = 0;
	(*map)->z_max = 0;
	(*map)->z_actual = 0;
	(*map)->z_x_y = 0;
	(*map)->t1 = 0.0f;
	(*map)->t2 = 0.0f;
	(*map)->scale = 5;
}
