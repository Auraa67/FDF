/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:58:45 by merazafi          #+#    #+#             */
/*   Updated: 2025/08/07 16:58:22 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_close_err(t_map *map, int fd, char *text_error)
{
	free(map);
	close(fd);
	print_error(text_error);
}

void	help_free(char **new_line)
{
	int	i;

	i = -1;
	while (new_line[++i])
		free(new_line[i]);
	free(new_line);
}

void	check_file(char *file, int argc)
{
	int		i;
	char	*str;
	int		begin;

	if (argc != 2)
		print_error("Error argument\n");
	if (ft_strlen(file) <= 4)
		print_error("Error file\n");
	i = 0;
	while (file[i])
		i++;
	while (file[i] != '.')
		i--;
	begin = i;
	while (file[i])
		i++;
	str = ft_substr(file, begin, i);
	if (ft_strcmp(str, ".fdf") != 0)
	{
		free(str);
		print_error("Error file\n");
	}
	free(str);
}

void	directory_file(char *file)
{
	int		i;
	char	*str;

	i = 0;
	while (file[i])
		i++;
	while (file[i] != '/')
		i--;
	str = ft_substr(file, i, 5);
	if (ft_strcmp(str, "/.fdf") == 0)
	{
		free(str);
		print_error("Error file\n");
	}
	free(str);
}

int	count_nbr(char *line)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	if (ft_strcmp(line, "\n") == 0)
	{
		return (1);
	}
	while (line[i] == ' ' && line[i])
		i++;
	while (line[i] != '\n' && line[i])
	{
		if (line[i] == ' ' && line[i + 1] != ' ')
		{
			nbr++;
		}
		i++;
	}
	if (line[i - 1] == ' ')
		return (nbr);
	else
		nbr++;
	return (nbr);
}
