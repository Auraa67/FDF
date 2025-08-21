/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:14:13 by merazafi          #+#    #+#             */
/*   Updated: 2025/07/14 11:13:50 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*a;

	len = 0;
	while (s[len])
		len++;
	a = malloc((len + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	len = 0;
	while (s[len])
	{
		a[len] = s[len];
		len++;
	}
	a[len] = '\0';
	return (a);
}

int	ft_count(char const *str)
{
	int	k;

	k = 0;
	while (str[k])
		k++;
	return (k);
}

static int	count_word(char *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c
				|| s[i + 1] == '\0'))
			k++;
		i++;
	}
	return (k);
}

static int	return_i(char *s, char c, unsigned int i)
{
	while (s[i] != c && s[i])
	{
		if (s[i] == '\n')
		{
			s[i] = '\0';
			break ;
		}
		i++;
	}
	return (i);
}

char	**ft_split(char *s, char c)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	j;
	unsigned int	words_number;
	char			**new_str;

	words_number = count_word(s, c);
	new_str = malloc(sizeof(char *) * (words_number + 1));
	if (new_str == NULL)
		return (NULL);
	i = -1;
	start = 0;
	j = 0;
	while (s[++i] && (j < words_number))
	{
		while (s[i] == c)
			i++;
		start = i;
		i = return_i(s, c, i);
		new_str[j] = ft_substr(s, start, (i - start));
		j++;
	}
	new_str[j] = NULL;
	return (new_str);
}
