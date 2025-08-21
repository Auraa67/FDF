/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:35:45 by merazafi          #+#    #+#             */
/*   Updated: 2025/07/01 12:33:46 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static char	*search_new_line(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	new_str = malloc((i + 2) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new_str[i] = '\n';
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static char	*extract_line(char *str, int i)
{
	int		len;
	int		k;
	char	*next_line;

	if (str[i] && str[i] == '\n')
	{
		len = ft_strlen(&str[i]);
		next_line = malloc(len * sizeof(char));
	}
	else
	{
		len = 0;
		next_line = malloc(len + 1 * sizeof(char));
	}
	if (!next_line)
		return (NULL);
	k = 0;
	if (str[i] == '\n' && str[i])
		i++;
	while (str[i])
		next_line[k++] = str[i++];
	next_line[k] = '\0';
	return (next_line);
}

static char	*continue_line(char *str)
{
	int		i;
	char	*next_line;

	i = 0;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	while (str[i] && str[i] != '\n')
		i++;
	next_line = extract_line(str, i);
	free(str);
	return (next_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd <= 0 || BUFFER_SIZE <= 0)
	{
		if (fd == -1)
			free(str);
		return (NULL);
	}
	str = fill_elemt(fd, str);
	if (!str)
		return (NULL);
	line = search_new_line(str);
	str = continue_line(str);
	return (line);
}
