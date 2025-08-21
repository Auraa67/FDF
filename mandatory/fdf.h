/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:32:36 by merazafi          #+#    #+#             */
/*   Updated: 2025/08/10 15:09:00 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69
# endif

# define COLOR_LOW  0xf0c91d 
# define COLOR_HIGH 0x871F78
# define WIN_X 1920
# define WIN_Y 1080
# define NO_COLOR -1
# define COS_30 0.866025404
# define SIN_30 0.5
# define MAX 2147483647
# define MIN -2147483648

typedef struct s_var
{
	int		i;
	float	t;
	int		j;
	int		fd;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		d_x;
	int		d_y;
	int		s_x;
	int		s_y;
	int		err1;
	int		steps;
	char	*line;
	int		check;
	char	**i_lgn;
	char	*color_for_one;
}				t_var;

typedef struct s_map
{
	int		i;
	void	*ptr;
	void	*win;
	void	*img;
	char	*addr;
	char	*valid;
	int		bpp;
	int		size_line;
	int		endian;
	int		height;
	int		width;
	float	zoom;
	float	offset_x;
	float	offset_y;
	int		**matrix;
	int		z_min;
	int		z_max;
	int		z_actual;
	int		z_x_y;
	float	t1;
	float	t2;
	int		color1;
	int		color2;
	int		color_z;
	int		scale;
	int		**color_def;
}				t_map;

size_t	ft_strlen(char *s);
int		handle(t_map *map);
int		ft_atoi(char *line);
int		ft_max(int a, int b);
void	min_max_z(t_map *map);
int		count_nbr(char *line);
void	free_color(t_map *map);
char	*get_next_line(int fd);
void	free_matrix(t_map *map);
void	init_struct(t_map **map);
float	ft_min(float x, float y);
void	print_error(char *error);
int		ft_count(char const *str);
char	*ft_strdup(const char *s);
void	directory_file(char *file);
void	help_free(char **new_line);
char	*check_overflow(char *line);
char	**ft_split(char *s, char c);
void	free_get(int fd, char *line);
int		ft_strcmp(char *s1, char *s2);
int		atoi_base(char *str, int base);
char	*fill_elemt(int fd, char *str);
int		handle_key(int key, t_map *map);
char	*ft_strjoin(char *s1, char *s2);
char	*search_comma(char *str, int c);
void	check_file(char *file, int argc);
void	rendering_map(t_map *map, t_var *var);
char	*check_letter_behind_value(char *line);
void	define_color_x(t_map *map, int i, int j);
void	define_color_y(t_map *map, int i, int j);
void	init_struct_pt2(t_var **var, t_map **map);
void	parsing(char *text, t_map *map, t_var *var);
void	init_height_and_width(char *text, t_map **map);
char	*valid_atoi(char *line, t_map *map, t_var *var);
void	bresenham(t_map *map, t_var *var, int x0, int y0);
void	no_color(char **all_line, t_map *map, t_var *var);
int		interpolate_color(int color1, int color2, float t);
void	free_close_err(t_map *map, int fd, char *text_error);
void	offset_zoom(t_map *map, int win_width, int win_height);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	free_all(t_map *map, t_var *var, char **int_line, char *line);
void	with_color(char **all_line, char *z_str, t_map *map, t_var *var);
void	checking_value_without_color(t_map *map, t_var *var, char **int_line);
void	define_map_color_without_color(t_map *map, char *type);
int		map_color_def_with_no_color(t_map *map, int i, int j, char *type);
void	map_def_color_equals_no_color(t_map *map, int i, int j, char *type);
void	map_def_color_equals_with_color(t_map *map, int i, int j, char *type);
void	verif_color_type(char **all_line, char *z_str, t_map *map, t_var *var);
void	checking_value_with_color(t_map *map,
			t_var *var, char **int_line, char *line);

#endif