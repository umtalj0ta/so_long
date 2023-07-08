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


int map_is_delimited_by_walls(int** map, int width, int height)
{
    int i;

    i = 0;

    // Canto superior
    while( map[i][0] != '\0' )
    {
        if( map[i][0] != '1' )
        {
            return 0;
        }

        i++;
    }
    // Canto inferior
    i = 0;

    while( map[i][ height - 1 ] != '\0' )
    {
        if( map[i][ height - 1 ] != '1' )
        {
            return 0;
        }

        i++;
    }

    // Canto Esquerdo
    i = 0;

    while( map[0][i] != '\0' )
    {
        if( map[0][i] != '1' )
        {
            return 0;
        }

        i++;
    }

    // Canto Direito
    i = 0;

    while( map[width - 1][i] != '\0' )
    {
        if( map[width - 1][i] != '1' )
        {
            return 0;
        }

        i++;
    }

    return 1;
}
void print_map(char** map, int width, int height) {
    // ANSI color codes for printing in RGB colors
    const char* color_reset = "\033[0m";
    const char* color_red = "\033[38;2;255;0;0m";
    const char* color_green = "\033[38;2;0;255;0m";

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j] == '1') {
                printf("%s%c%s ", color_green, map[i][j], color_reset);
            } else {
                printf("%s%c%s ", color_red, map[i][j], color_reset);
            }
        }
        printf("\n");
    }
}
