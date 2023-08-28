#include "../so_long.h"
#include "../include/window.h"


int main(int argc, char **argv)
{
    t_data  data;
    ft_bzero(&data, sizeof(t_data));
    ft_bzero(&data.plr, sizeof(t_plr));
    check_arguments(argc, argv, &data);
    ft_map_init(&data, argv[1]);
	ft_map_check(&data);
	ft_game_init(&data);
	ft_render_xpm(&data);
	ft_render_map(&data);
	data.plr.to_collect = data.map.n_collectibles;
	mlx_hook(data.mlx.win, 2, 1L << 0, ft_keypress, &data);
	mlx_hook(data.mlx.win, 17, 1L << 17, ft_close_and_destroy, &data);
	mlx_loop(data.mlx.mlx);

}

void    check_arguments(int argc, char **argv, t_data *data)
{
    int i;

    i = ft_strlen(argv[1]);
    if(argc != 2)
        ft_perror(" Error, it should be ./so_long map.ber\n", data);
    if(argv[1][i - 1] != 'r' || argv[1][i - 2] != 'e' || argv[1][i - 3] != 'b' || argv[1][i - 4] != '.')
        ft_perror(" Error, it should be ./so_long map.ber\n", data);
}

void	ft_perror(char *str, t_data *data)
{
	printf("%s", str);
	ft_close_and_destroy(data);
	exit(0);
}

//flood fill
int flood_fill(t_data *d, char **map, int x, int y)
{
    int n_collect;
    static int collectible;
    static int exit;

    n_collect = d->map.n_collectibles;
    if(map[y][x] == '1')
        return 0;
    else if(map[y][x] == 'C')
        collectible = collectible + 1;
    else if (map[y][x] == 'E')
    {
        exit = 1;
        return 0;
    }
     	map[y][x] = '1';
	flood_fill(d, map, x + 1, y);
	flood_fill(d, map, x - 1, y);
	flood_fill(d, map, x, y + 1);
	flood_fill(d, map, x, y - 1);
	if (collectible == n_collect && exit == 1)
		return (1);
	else
		return (0);           
}