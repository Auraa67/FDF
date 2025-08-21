/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:20:14 by merazafi          #+#    #+#             */
/*   Updated: 2025/08/06 19:12:54 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	return (nbr);
}

static void	put_pixel(t_map *map, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || y < 0 || x >= 1920 || y >= 1080)
	{
		return ;
	}
	dest = map->addr + (y * map->size_line) + (x * (map->bpp / 8));
	*(unsigned int *)dest = color;
}

static void	assign_var(t_var *var, int x0, int y0)
{
	var->d_x = ft_abs(var->x1 - x0);
	var->d_y = ft_abs(var->y1 - y0);
	var->steps = ft_max(var->d_x, var->d_y);
	var->err1 = var->d_x - var->d_y;
	if (x0 < var->x1)
		var->s_x = 1;
	else
		var->s_x = -1;
	if (y0 < var->y1)
		var->s_y = 1;
	else
		var->s_y = -1;
}

static void	assign_t(t_map *map, t_var *var)
{
	if (var->steps)
		var->t = (float)map->i / var->steps;
	else
		var->t = 0;
}

void	bresenham(t_map *map, t_var *var, int x0, int y0)
{
	int		err2;

	assign_var(var, x0, y0);
	map->i = 0;
	while (1)
	{
		assign_t(map, var);
		map->color_z = interpolate_color(map->color1, map->color2, var->t);
		err2 = 2 * var->err1;
		put_pixel(map, x0, y0, map->color_z);
		if (x0 == var->x1 && y0 == var->y1)
			break ;
		if (err2 > -var->d_y)
		{
			var->err1 -= var->d_y;
			x0 += var->s_x;
		}
		if (err2 < var->d_x)
		{
			var->err1 += var->d_x;
			y0 += var->s_y;
		}
		map->i++;
	}
}
