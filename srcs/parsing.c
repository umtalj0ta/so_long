

#include "../so_long.h"

int map_is_rectangular(char** map, int height, int width) {
    int i = 0;
    while (i < height) {
        if ((int)strlen(map[i]) != width) {
            return 0;
        }
        i++;
    }
    return 1;
}

int map_is_delimited_by_walls(char** map, int width, int height)
{
    int i = 0;

    if (!map || width == 0 || height == 0) 
        return 0;

    // Check top and bottom walls
    while (i < width) 
        {
            if (map[i][0] != '1' || map[i][height - 1] != '1') 
                return 0;
        i++;
        }
    // Check left and right walls
    i = 0;
    while (i < height)  
        {
            if (map[0][i] != '1' || map[width - 1][i] != '1') 
                return 0;
        i++;
        }
    return 1;
}

// int map_has_valid_simbols(char **map, int width, int height)
// {
//     int i;
//     int exit;
//     int spawn;
//     int collectible;

// )