/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:28:21 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/08/29 13:32:38 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../include/window.h"

int		ft_close_and_destroy(t_data *data);
void	ft_destroy_display(t_data *data);
void	ft_free_map(char **map);
void	ft_free_sprites(t_data *data);

int	ft_close_and_destroy(t_data *data)
{
	end_game(data);
	exit(0);
	return (0);
}

void	end_game(t_data *data)
{
	ft_free_sprites(data);
	ft_free_map(data->map.map);
	mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	free(data->mlx.mlx);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_free_sprites(t_data *data)
{
	if (data->spr.f_img)
		mlx_destroy_image(data->mlx.mlx, data->spr.f_img);
	if (data->spr.p_img)
		mlx_destroy_image(data->mlx.mlx, data->spr.p_img);
	if (data->spr.c_img)
		mlx_destroy_image(data->mlx.mlx, data->spr.c_img);
	if (data->spr.e_img)
		mlx_destroy_image(data->mlx.mlx, data->spr.e_img);
	if (data->spr.w_img)
		mlx_destroy_image(data->mlx.mlx, data->spr.w_img);
}
