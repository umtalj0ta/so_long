#include "../so_long.h"
#include "../include/window.h"


void	ft_game_init(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		ft_perror("Error\nmlx_init() failed", data);
	data->mlx.win = mlx_new_window(data->mlx.mlx,
			SIZE * data->map.n_columns, SIZE * data->map.n_rows, "so_long");
	if (!data->mlx.win)
	{
		free(data->mlx.mlx);
		ft_perror("Error\nmlx_new_window() failed", data);
	}
}