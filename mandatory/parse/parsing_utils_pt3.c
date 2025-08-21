/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_pt3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:48:01 by merazafi          #+#    #+#             */
/*   Updated: 2025/08/06 18:01:45 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_total;
	char	*str;
	char	*string;

	len_total = ft_count(s);
	string = (char *)s;
	if (!string)
		return (NULL);
	else if (start >= len_total)
		return (ft_strdup(""));
	else if (len > len_total - start)
		len = len_total - start;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = string[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	with_color(char **all_line, char *z_str, t_map *map, t_var *var)
{
	if (ft_strcmp(valid_atoi(z_str, map, var), "Invalid") == 0)
	{
		free_all(map, var, all_line, var->line);
		free(z_str);
		print_error("Invalid value in map\n");
	}
	free(z_str);
}

void	no_color(char **all_line, t_map *map, t_var *var)
{
	if (ft_strcmp(valid_atoi(all_line[var->i], map, var), "Invalid") == 0)
	{
		free_all(map, var, all_line, var->line);
		print_error("Invalid value in map\n");
	}
}

static void	free_all_print_err(char **all_line, char *z_str,
t_map *map, t_var *var)
{
	free_all(map, var, all_line, var->line);
	free(z_str);
	print_error("this color in hexa doesn't exist\n");
}

void	verif_color_type(char **all_line, char *z_str, t_map *map, t_var *var)
{
	int	i;

	if (var->color_for_one[0] != '0'
		|| ft_strlen(var->color_for_one) > 8
		|| ft_strlen(var->color_for_one) <= 2
		|| (var->color_for_one[1] != 'x' && var->color_for_one[1] != 'X'))
	{
		free_all_print_err(all_line, z_str, map, var);
	}
	i = 2;
	while (var->color_for_one[i])
	{
		if (var->color_for_one[i] >= '0' && var->color_for_one[i] <= '9')
			i++;
		else if (var->color_for_one[i] >= 'a' && var->color_for_one[i] <= 'f')
			i++;
		else if (var->color_for_one[i] >= 'A' && var->color_for_one[i] <= 'F')
			i++;
		else
			free_all_print_err(all_line, z_str, map, var);
	}
}
