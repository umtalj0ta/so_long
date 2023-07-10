#include <stdio.h>
#include "../so_long.h"
#include <assert.h>

int main() {
    // Test map_is_rectangular with a rectangular map
    char* map1[] = {"111", "100", "111"};
    int height1 = 3;
    int width1 = 3;
    assert(map_is_rectangular(map1, height1, width1) == 1);

    // Test map_is_rectangular with a non-rectangular map
    char* map2[] = {"111", "10", "111"};
    int height2 = 3;
    int width2 = 3;
    assert(map_is_rectangular(map2, height2, width2) == 0);

    // Test map_is_rectangular with an empty map
    char* map3[] = {};
    int height3 = 0;
    int width3 = 0;
    assert(map_is_rectangular(map3, height3, width3) == 1);

    // Test map_is_delimited_by_walls with a valid map
    char* map4[] = {"111", "101", "111"};
    int height4 = 3;
    int width4 = 3;
    assert(map_is_delimited_by_walls(map4, height4, width4) == 1);

    // Test map_is_delimited_by_walls with an invalid map
    char* map5[] = {"111", "100", "111"};
    int height5 = 3;
    int width5 = 3;
    assert(map_is_delimited_by_walls(map5, height5, width5) == 0);

    // Test map_is_delimited_by_walls with a map that has no walls
    char* map6[] = {"000", "000", "000"};
    int height6 = 3;
    int width6 = 3;
    assert(map_is_delimited_by_walls(map6, height6, width6) == 0);

    // Test map_is_delimited_by_walls with an empty map
    char* map7[] = {};
    int height7 = 0;
    int width7 = 0;
    assert(map_is_delimited_by_walls(map7, height7, width7) == 0);

    printf("All tests passed!\n");
    return 0;
}