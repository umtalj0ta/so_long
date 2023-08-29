/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:28:42 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/08/29 13:29:58 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../include/window.h"

void	ft_map_check(t_data *data);
int		ft_check_characters(t_data *data);
int		ft_check_retangular(t_data *data);
int		ft_check_walls(t_data *data);
int		ft_check_path(t_data *data);

void	ft_map_check(t_data *data)
{
	if (data->map.n_rows < 3 || data->map.n_columns < 5)
		ft_perror("Error\nInvalid map too small\n", data);
	if (ft_check_characters(data) == 0)
		ft_perror("Error\nInvalid map wrong number of map obejects\n", data);
	if (ft_check_retangular(data) == 0)
		ft_perror("Error\nInvalid map not retangular\n", data);
	if (ft_check_walls(data) == 0)
		ft_perror("Error\nInvalid map not surrounded by walls\n", data);
	if (ft_check_path(data) == 0)
		ft_perror("Error\nInvalid map no valid path\n", data);
}

int	ft_check_characters(t_data *d)
{
	d->i = 0;
	while (d->i < d->map.n_rows)
	{
		d->j = 0;
		while (d->j < d->map.n_columns)
		{
			if (d->map.map[d->i][d->j] == 'C')
				d->map.n_collectibles++;
			else if (d->map.map[d->i][d->j] == 'E')
				d->map.n_exits++;
			else if (d->map.map[d->i][d->j] == 'P')
			{
				d->map.n_players++;
				d->plr.p_r = d->i;
				d->plr.p_c = d->j;
			}
			else if (ft_strchr("01CEP", d->map.map[d->i][d->j]) == 0)
				ft_perror("Error\nInvalid map - wrong character was found\n", d);
			d->j++;
		}
		d->i++;
	}
	return (d->map.n_collectibles >= 1 && d->map.n_exits == 1
		&& d->map.n_players == 1);
}

int	ft_check_retangular(t_data *d)
{
	d->i = 0;
	while (d->i < d->map.n_rows)
	{
		if (ft_strlen(d->map.map[d->i]) != d->map.n_columns)
			return (0);
		d->i++;
	}
	return (1);
}

int	ft_check_walls(t_data *d)
{
	d->i = 0;
	while (d->i < d->map.n_rows)
	{
		if (d->map.map[d->i][0] != '1'
				|| d->map.map[d->i][d->map.n_columns - 1] != '1')
			return (0);
		d->i++;
	}
	d->i = 0;
	while (d->i < d->map.n_columns)
	{
		if (d->map.map[0][d->i] != '1'
				|| d->map.map[d->map.n_rows - 1][d->i] != '1')
			return (0);
		d->i++;
	}
	return (1);
}

int	ft_check_path(t_data *d)
{
	int		e;
	char	**map_cpy;

	d->i = 0;
	e = 0;
	map_cpy = ft_calloc(d->map.n_rows + 1, sizeof(char *));
	if (!map_cpy)
		ft_perror("Error\nMalloc failed\n", d);
	while (d->i < d->map.n_rows)
	{
		map_cpy[d->i] = ft_strdup(d->map.map[d->i]);
		{
			if (!d->map.map[d->i])
			{
				ft_free_map(map_cpy);
				ft_perror("Error\nMalloc failed\n", d);
			}
		}
		d->i++;
	}
	e = flood_fill(d, map_cpy, d->plr.p_r, d->plr.p_c);
	ft_free_map(map_cpy);
	return (e);
}
