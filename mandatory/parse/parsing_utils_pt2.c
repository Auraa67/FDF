/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_pt2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:09:29 by merazafi          #+#    #+#             */
/*   Updated: 2025/08/06 17:21:39 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	print_error(char *error)
{
	int		len;
	ssize_t	written;

	len = ft_strlen(error);
	written = write(2, error, len);
	if (written == -1)
	{
		exit(1);
	}
	exit(1);
}

char	*valid_atoi(char *line, t_map *map, t_var *var)
{
	int	sign_nbr[2];

	map->i = 0;
	var->check = 0;
	sign_nbr[0] = 1;
	sign_nbr[1] = 0;
	while (line[map->i] == ' ')
		map->i++;
	if (line[map->i] == '+' || line[map->i] == '-')
	{
		if (line[map->i] == '-')
			sign_nbr[0] = -sign_nbr[0];
		map->i++;
	}
	while (line[map->i] >= '0' && line[map->i] <= '9' && line[map->i])
	{
		sign_nbr[1] = (sign_nbr[1] * 10) + (line[map->i] - '0');
		map->i++;
		var->check = 1;
	}
	if (line[map->i] == '\0')
		var->check = 1;
	if (var->check == 0)
		return ("Invalid");
	return ("Valid");
}

char	*search_comma(char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

int	atoi_base(char *str, int base)
{
	int	result;
	int	digit;
	int	i;

	i = 0;
	result = 0;
	if ((str[0] == '0' && ((str[1] == 'x' || str[1] == 'X'))))
		i += 2;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			digit = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			digit = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			digit = str[i] - 'A' + 10;
		else
			break ;
		if (digit >= base)
			break ;
		result = result * base + digit;
		i++;
	}
	return (result);
}
