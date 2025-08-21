/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:05:34 by merazafi          #+#    #+#             */
/*   Updated: 2025/08/06 17:55:59 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

char	*check_overflow(char *line)
{
	long	i;
	long	sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '+' || line[i] == '-')
	{
		if (line[i] == '-')
			sign = -sign;
		i++;
	}
	while (line[i] >= '0' && line[i] <= '9')
	{
		nbr = (nbr * 10) + (line[i] - '0');
		i++;
	}
	if ((nbr * sign) >= MIN && (nbr * sign) <= MAX)
	{
		return ("OK");
	}
	return ("Error");
}

int	ft_atoi(char *line)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '+' || line[i] == '-')
	{
		if (line[i] == '-')
			sign = -sign;
		i++;
	}
	while (line[i] >= '0' && line[i] <= '9')
	{
		nbr = (nbr * 10) + (line[i] - '0');
		i++;
	}
	if ((nbr * sign) >= 214647)
		return (214647);
	if ((nbr * sign) <= -214647)
		return (-214647);
	return (nbr * sign);
}

static void	fill_matrix(t_map *map, t_var *var, int *z_line, int *color_line)
{
	char	*z_str;

	var->i_lgn = ft_split(var->line, ' ');
	var->i = -1;
	while (var->i_lgn[++var->i])
	{
		if (search_comma(var->i_lgn[var->i], ','))
		{
			z_str = ft_substr(var->i_lgn[var->i], 0,
					search_comma(var->i_lgn[var->i], ',') - var->i_lgn[var->i]);
			var->color_for_one = search_comma(var->i_lgn[var->i], ',') + 1;
			verif_color_type(var->i_lgn, z_str, map, var);
			z_line[var->i] = ft_atoi(z_str);
			checking_value_with_color(map, var, var->i_lgn, z_str);
			color_line[var->i] = atoi_base(var->color_for_one, 16);
		}
		else
		{
			z_line[var->i] = ft_atoi(var->i_lgn[var->i]);
			checking_value_without_color(map, var, var->i_lgn);
			color_line[var->i] = NO_COLOR;
		}
		free(var->i_lgn[var->i]);
	}
	free(var->i_lgn);
}

static void	init_tab(t_map *map)
{
	int	i;

	map->matrix = malloc(sizeof(int *) * (map->height + 1));
	if (!map->matrix)
		return ;
	i = -1;
	while (++i < map->height)
	{
		map->matrix[i] = malloc(sizeof(int) * (map->width + 1));
		if (!map->matrix[i])
			return ;
	}
	map->color_def = malloc(sizeof(int *) * (map->height + 1));
	if (!map->color_def)
		return ;
	i = -1;
	while (++i < map->height)
	{
		map->color_def[i] = malloc(sizeof(int) * (map->width + 1));
		if (!map->color_def[i])
			return ;
	}
}

void	parsing(char *text, t_map *map, t_var *var)
{
	int		i;

	init_tab(map);
	var->fd = open(text, O_RDONLY);
	if (var->fd == -1)
		return ;
	i = 0;
	while (1)
	{
		var->line = get_next_line(var->fd);
		if (!var->line)
			break ;
		fill_matrix(map, var, map->matrix[i], map->color_def[i]);
		free(var->line);
		i++;
	}
	close(var->fd);
}
