
#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# if defined(__APPLE__) && defined(__MACH__)
#  include "mlx/mlx.h"
# else
#  include "mlx_linux/mlx.h"
# endif

# include "./libft/libft.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17

# if defined(__APPLE__) && defined(__MACH__)
#  define LEFT_KEY				123	
#  define RIGHT_KEY				124	
#  define UP_KEY				126
#  define DOWN_KEY				125	
#  define A_KEY					0
#  define S_KEY					1
#  define D_KEY					2
#  define W_KEY					13
#  define ESC 					53

# else
#  define LEFT_KEY				65361
#  define RIGHT_KEY				65363
#  define UP_KEY				65362
#  define DOWN_KEY				65364
#  define A_KEY					97
#  define W_KEY					119
#  define S_KEY					115
#  define D_KEY					100
#  define ESC					65307
# endif

# define SPRITE_H				64
# define SPRITE_W				64

int map_is_delimited_by_walls(int** map, int width, int height);
int map_is_rectangular(char** map, int height, int width);


#endif
