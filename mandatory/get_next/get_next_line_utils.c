/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:35:28 by merazafi          #+#    #+#             */
/*   Updated: 2025/07/01 12:33:55 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != (char)c)
	{
		if ((s[i] == '\0') && (c != s[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*ft_new_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len_i;
	size_t	len_j;
	char	*result;

	i = -1;
	j = -1;
	len_i = ft_strlen(s1);
	len_j = ft_strlen(s2);
	result = malloc(sizeof(char) * (len_i + len_j + 1));
	if (!result)
		return (NULL);
	while (++i < len_i)
		result[i] = s1[i];
	while (++j < len_j)
		result[i + j] = s2[j];
	result[i + j] = '\0';
	free(s1);
	return (result);
}

static char	*read_until_newline(int fd, char *str, int fd_read)
{
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!(ft_strchr(str, '\n')) && fd_read != 0)
	{
		fd_read = read(fd, buff, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[fd_read] = '\0';
		str = ft_new_strjoin(str, buff);
		if (!str)
		{
			free(buff);
			return (NULL);
		}
	}
	free(buff);
	return (str);
}

char	*fill_elemt(int fd, char *str)
{
	if (fd < 0)
		return (NULL);
	str = read_until_newline(fd, str, 1);
	return (str);
}
