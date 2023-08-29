/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:28:46 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/08/29 13:36:17 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/window.h"
#include "../so_long.h"
#include <fcntl.h>

void	ft_map_init(t_data *data, char *path)
{
	data->map.fd = open(path, O_RDONLY);
	if (data->map.fd == -1)
		ft_perror("Error", data);
	data->map.n_columns = count_columns(data->map.fd);
	data->map.n_rows = count_rows(data->map.fd);
	data->map.map = ft_create_map_array(data, path);
	data->map.n_collectibles = 0;
	data->map.n_exits = 0;
	data->map.n_players = 0;
	close(data->map.fd);
}

int	count_columns(int fd)
{
	char	c;
	int		i;

	i = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		i++;
	}
	return (i);
}

int	count_rows(int fd)
{
	char	c;
	int		i;

	i = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			i++;
	}
	return (i + 1);
}

char	**ft_create_map_array(t_data *data, char *path)
{
	int		fd;
	char	*line;
	char	**map;

	data->i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_perror("Error\nMap file not found\n", data);
	map = (char **)malloc(sizeof(char *) * (data->map.n_rows + 1));
	if (!map)
		ft_perror("Error\nMalloc failed\n", data);
	while (data->i < data->map.n_rows)
	{
		line = get_next_line(fd);
		if (!line)
			ft_perror("Error\nMalloc failed\n", data);
		map[data->i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!map[data->i])
			ft_perror("Error\nMalloc failed\n", data);
		ft_strlcpy(map[data->i], line, ft_strlen(line));
		free(line);
		data->i++;
	}
	close(fd);
	return (map);
}
