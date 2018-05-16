/*
** EPITECH PROJECT, 2018
** special_malloc.c
** File description:
** elaborate malloc
*/
#include "my.h"

int malloc_2d_array(world_t *wd)
{
	int y = 0;

	wd->map.map3d = malloc(sizeof(float *) * MAP_Y);
	while (y != MAP_Y) {
		wd->map.map3d[y] = malloc(sizeof(float) * MAP_X);
		y++;
	}
	return (0);
}

sfVector2f **malloc_2dmap()
{
	int y = 0;
	sfVector2f **map2d;

	map2d = malloc(sizeof(sfVector2f *) * MAP_Y);
	while (y != MAP_Y) {
		map2d[y] = malloc(sizeof(sfVector2f) * MAP_X);
		y++;
	}
	return (map2d);
}
