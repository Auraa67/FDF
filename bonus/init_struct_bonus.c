/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:14:46 by merazafi          #+#    #+#             */
/*   Updated: 2025/08/10 14:30:33 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

static void	init_height_and_width(char *text, t_map **map)
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

void	init_struct_var(t_var **var)
{
	(*var) = malloc(sizeof(t_var));
	if (!*var)
		return ;
	(*var)->i = 0;
	(*var)->t = 0.0f;
	(*var)->j = 0;
	(*var)->fd = -1;
	(*var)->x0 = 0;
	(*var)->y0 = 0;
	(*var)->x1 = 0;
	(*var)->y1 = 0;
	(*var)->d_x = 0;
	(*var)->d_y = 0;
	(*var)->s_x = 0;
	(*var)->s_y = 0;
	(*var)->err1 = 0;
	(*var)->steps = 0;
	(*var)->line = NULL;
	(*var)->check = 0;
	(*var)->i_lgn = NULL;
	(*var)->color_for_one = NULL;
}

static void	init_struct_map_pt2(t_map **map)
{
	(*map)->t1 = 0.0f;
	(*map)->t2 = 0.0f;
	(*map)->color1 = 0;
	(*map)->color2 = 0;
	(*map)->color_z = 0;
	(*map)->color_def = 0;
	(*map)->scale_x_y = 5.0f;
	(*map)->scale_z = 2.0f;
	(*map)->x_rot = 0;
	(*map)->y_rot = 0;
	(*map)->z_rot = 0;
	(*map)->angle_degree = 0;
	(*map)->angle_radian = 0;
}

void	init_struct_map(t_map **map, char *text)
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
	(*map)->height = 0;
	(*map)->width = 0;
	init_height_and_width(text, map);
	(*map)->zoom = 1.1;
	(*map)->offset_x = 0.0f;
	(*map)->offset_y = 0.0f;
	(*map)->matrix = 0;
	(*map)->z_min = 0;
	(*map)->z_max = 0;
	(*map)->z_actual = 0;
	(*map)->z_x_y = 0;
	init_struct_map_pt2(map);
}
