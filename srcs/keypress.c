/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:28:33 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/08/29 13:36:36 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../include/window.h"

int	ft_keypress(int keycode, t_data *data);
int	ft_move_player(t_data *d, int x, int y);

int	ft_keypress(int keycode, t_data *data)
{
	int	to_print;

	to_print = 0;
	if (keycode == ESC)
		ft_close_and_destroy(data);
	else if (keycode == UP_KEY)
		to_print = ft_move_player(data, data->plr.p_c, data->plr.p_r - 1);
	else if (keycode == LEFT_KEY)
		to_print = ft_move_player(data, data->plr.p_c - 1, data->plr.p_r);
	else if (keycode == DOWN_KEY)
		to_print = ft_move_player(data, data->plr.p_c, data->plr.p_r + 1);
	else if (keycode == RIGHT_KEY)
		to_print = ft_move_player(data, data->plr.p_c + 1, data->plr.p_r);
	if (to_print == 1)
		printf("Moves: %i\n", data->plr.n_moves);
	return (0);
}

int	ft_move_player(t_data *d, int x, int y)
{
	if (d->map.map[y][x] == '0' || d->map.map[y][x] == 'C')
	{
		mlx_put_image_to_window(d->mlx.mlx, d->mlx.win,
			d->spr.f_img, d->plr.p_c * SIZE, d->plr.p_r * SIZE);
		mlx_put_image_to_window(d->mlx.mlx, d->mlx.win,
			d->spr.p_img, x * SIZE, y * SIZE);
		if (d->map.map[y][x] == 'C')
			d->plr.to_collect--;
		d->map.map[d->plr.p_r][d->plr.p_c] = '0';
		d->map.map[y][x] = '0';
		d->plr.p_c = x;
		d->plr.p_r = y;
		d->plr.n_moves++;
		return (1);
	}
	if (d->map.map[y][x] == 'E' && d->plr.to_collect == 0)
	{
		printf("Moves: %i\n", d->plr.n_moves + 1);
		printf("Congratulations, you finished the game!\n");
		ft_close_and_destroy(d);
	}
	return (0);
}
