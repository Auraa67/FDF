/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parse_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:23:11 by merazafi          #+#    #+#             */
/*   Updated: 2025/08/05 19:49:22 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

char	*check_letter_behind_value(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '+' || line[i] == '-')
	{
		i++;
	}
	while (line[i])
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			i++;
		}
		else
		{
			return ("Error");
		}
	}
	return ("Ok");
}

void	checking_value_without_color(t_map *map, t_var *var, char **int_line)
{
	if (ft_strcmp(check_letter_behind_value(int_line[var->i]), "Error") == 0
		|| ft_strcmp(check_overflow(int_line[var->i]), "Error") == 0)
	{
		free_all(map, var, int_line, var->line);
		print_error("Invalid value in map\n");
	}
	no_color(var->i_lgn, map, var);
}

void	checking_value_with_color(t_map *map,
t_var *var, char **int_line, char *line)
{
	if (ft_strcmp(check_letter_behind_value(line), "Error") == 0
		|| ft_strcmp(check_overflow(line), "Error") == 0)
	{
		free_all(map, var, int_line, var->line);
		free(line);
		print_error("Invalid value in map\n");
	}
	with_color(var->i_lgn, line, map, var);
}

void	free_get(int fd, char *line)
{
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		free(line);
	}
	close(fd);
}

void	free_all(t_map *map, t_var *var, char **int_line, char *line)
{
	while (int_line[var->i])
	{
		free(int_line[var->i]);
		var->i++;
	}
	free(int_line);
	free_get(var->fd, line);
	free_matrix(map);
	free_color(map);
	free(var);
	free(map);
}
