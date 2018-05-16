/*
** EPITECH PROJECT, 2018
** map_create
** File description:
** create 2d map
*/
#include "my.h"
#include "open_window.h"
#include <math.h>

int fill_map3d(world_t *wd)
{
	int a = 0;
	int i = 0;

	malloc_2d_array(wd);
	while (a != MAP_Y) {
		while (i != MAP_X) {
			wd->map.map3d[a][i] = 0;
			i++;
		}
		a++;
		i = 0;
	}
	return (0);
}

int coord_map(world_t *wd)
{
	int x = 0;
	int y = 0;

	while (y != MAP_Y) {
		while (x != MAP_X) {
			wd->map.map2d[y][x] = project_iso_point(x, y, wd);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

sfVector2f project_iso_point(int x, int y, world_t *wd)
{
	sfVector2f vector;
	float z = wd->map.map3d[y][x];
	float scale_x = 30;
	float scale_y = 30;

	vector.x = (cos(0.785398) * x - cos(0.785398) * y)
		+ WIDTH / (scale_x + scale_x) + wd->cam.mouv_x
		- wd->cam.zoom*5+5;
	vector.y = (sin(0.610865) * (wd->cam.incline_y) * y +
		sin(0.610865) * (wd->cam.incline_y) * x - z)
		+ 10 +wd->cam.mouv_y - wd->cam.zoom*5+5;
	vector.x *= scale_x * wd->cam.zoom;
	vector.y *= scale_y * wd->cam.zoom;
	return (vector);
}
