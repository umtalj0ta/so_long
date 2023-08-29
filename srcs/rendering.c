/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:28:54 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/08/29 13:31:47 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/window.h"
#include "../so_long.h"

// use mlx_xpm_file_to_image() to render the textures
void	ft_render_xpm(t_data *d)
{
	d->spr.w_img = mlx_xpm_file_to_image(d->mlx.mlx, 
			"assets/textures/wall.xpm",
			&d->spr.width, &d->spr.height);
	d->spr.p_img = mlx_xpm_file_to_image(d->mlx.mlx, 
			"assets/textures/player.xpm",
			&d->spr.width, &d->spr.height);
	d->spr.c_img = mlx_xpm_file_to_image(d->mlx.mlx, 
			"assets/textures/collectible.xpm",
			&d->spr.width, &d->spr.height);
	d->spr.e_img = mlx_xpm_file_to_image(d->mlx.mlx, 
			"assets/textures/exit.xpm",
			&d->spr.width, &d->spr.height);
	d->spr.f_img = mlx_xpm_file_to_image(d->mlx.mlx, 
			"assets/textures/floor.xpm",
			&d->spr.width, &d->spr.height);
	if (!d->spr.w_img || !d->spr.p_img || !d->spr.c_img
		|| !d->spr.e_img || !d->spr.f_img)
		ft_perror("Error\nmlx_xpm_file_to_image() failed", d);
}

// render the map to the window
void	ft_render_map(t_data *d)
{
	d->i = 0;
	while (d->i < d->map.n_rows)
	{
		d->j = 0;
		while (d->j < d->map.n_columns)
		{
			if (d->map.map[d->i][d->j] == '1')
				mlx_put_image_to_window(d->mlx.mlx, d->mlx.win,
					d->spr.w_img, d->j * SIZE, d->i * SIZE);
			else if (d->map.map[d->i][d->j] == 'P')
				mlx_put_image_to_window(d->mlx.mlx, d->mlx.win,
					d->spr.p_img, d->j * SIZE, d->i * SIZE);
			else if (d->map.map[d->i][d->j] == 'C')
				mlx_put_image_to_window(d->mlx.mlx, d->mlx.win,
					d->spr.c_img, d->j * SIZE, d->i * SIZE);
			else if (d->map.map[d->i][d->j] == 'E')
				mlx_put_image_to_window(d->mlx.mlx, d->mlx.win,
					d->spr.e_img, d->j * SIZE, d->i * SIZE);
			else if (d->map.map[d->i][d->j] == '0')
				mlx_put_image_to_window(d->mlx.mlx, d->mlx.win,
					d->spr.f_img, d->j * SIZE, d->i * SIZE);
			d->j++;
		}
		d->i++;
	}
}
