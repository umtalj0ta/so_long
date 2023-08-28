 #ifndef WINDOW_H
# define WINDOW_H

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_map
{
	int				fd;
	char			**map;
	unsigned int	n_columns;
	unsigned int	n_rows;
	unsigned int	n_collectibles;
	unsigned int	n_exits;
	unsigned int	n_players;
}				t_map;

typedef struct s_player
{
	int		p_c;
	int		p_r;
	int		n_moves;
	int		to_collect;
}				t_plr;

typedef struct s_spr
{
	void	*w_img;
	void	*p_img;
	void	*c_img;
	void	*e_img;
	void	*f_img;
	int		width;
	int		height;
}				t_spr;

typedef struct s_data
{
	t_mlx			mlx;
	t_map			map;
	t_spr			spr;
	t_plr			plr;
	unsigned int	i;
	unsigned int	j;
}				t_data;


void	check_arguments(int argc, char **argv, t_data *data);
void	ft_perror(char *str, t_data *data);
int		flood_fill(t_data *d, char **map, int x, int y);
void	ft_map_init(t_data *data, char *path);
int		count_columns(int fd);
int		count_rows(int fd);
char	**ft_create_map_array(t_data *data, char *path);
void	ft_map_check(t_data *data);
int		ft_check_characters(t_data *data);
int		ft_check_retangular(t_data *data);
int		ft_check_walls(t_data *data);
int		ft_check_path(t_data *data);
void	ft_game_init(t_data *data);
void	ft_render_xpm(t_data *d);
void	ft_render_map(t_data *d);
int		ft_keypress(int keycode, t_data *data);
int		ft_move_player(t_data *d, int x, int y);
int		ft_close_and_destroy(t_data *data);
void	end_game(t_data *data);
void	ft_free_map(char **map);
void	ft_free_sprites(t_data *data);
char	*ft_read_to_backup(int fd, char *backup);
char	*ft_get_line(char *backup);
char	*ft_clean_backup(char *backup);
char	*get_next_line(int fd);
char	*ft_join(char *previous, const char *current);

#endif