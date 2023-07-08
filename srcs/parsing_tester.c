#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../so_long.h"

static void test_map_is_rectangular_valid(void **state) {
    char* map[] = {"111", "111", "111"};
    assert_true(map_is_rectangular(map, 3, 3));
}

static void test_map_is_rectangular_invalid(void **state) {
    char* map[] = {"111", "1111", "111"};
    assert_false(map_is_rectangular(map, 3, 4));
}

static void test_map_is_delimited_by_walls_valid(void **state) {
    int map[4][4] = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 1}
    };
    assert_true(map_is_delimited_by_walls((int**)map, 4, 4));
}

static void test_map_is_delimited_by_walls_invalid(void **state) {
    int map[4][4] = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 0},
        {1, 1, 1, 1}
    };
    assert_false(map_is_delimited_by_walls((int**)map, 4, 4));
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_map_is_rectangular_valid),
        cmocka_unit_test(test_map_is_rectangular_invalid),
        cmocka_unit_test(test_map_is_delimited_by_walls_valid),
        cmocka_unit_test(test_map_is_delimited_by_walls_invalid),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}