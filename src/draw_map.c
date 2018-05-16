/*
** EPITECH PROJECT, 2017
** File Name : draw_map.c
** File description:
** Rémi BISSON
*/
#include "my.h"

sfColor get_shadow(sfConvexShape *shape)
{
	sfColor color;
	float y1 = sfConvexShape_getPoint(shape, 2).y;
	float y2 = sfConvexShape_getPoint(shape, 0).y;
	float x1 = sfConvexShape_getPoint(shape, 3).x;
	float x2 = sfConvexShape_getPoint(shape, 1).x;
	float tile_height = ABS(y1 - y2);
	float tile_width = ABS(x2 - x1);
	float ratio;

	if (tile_width != 0)
		ratio = tile_height / tile_width;
	ratio = 125 * ratio + 125;
	if (ratio < 100)
		ratio = 100;
	else if (ratio > 255)
		ratio = 255;
	color.r = ratio;
	color.g = ratio;
	color.b = ratio;
	color.a = 255;
	return (color);
}

int draw_shape(world_t *wd, object_t *obj_arr, int x, int y)
{
	sfConvexShape *shape = sfConvexShape_create();

	if (shape == NULL)
		return (-1);
	sfConvexShape_setPointCount(shape, 4);
	sfConvexShape_setPoint(shape, 0, wd->map.map2d[y][x]);
	sfConvexShape_setPoint(shape, 1, wd->map.map2d[y][x + 1]);
	sfConvexShape_setPoint(shape, 2, wd->map.map2d[y + 1][x + 1]);
	sfConvexShape_setPoint(shape, 3, wd->map.map2d[y + 1][x]);
	sfConvexShape_setTexture(shape, obj_arr[5].texture, sfTrue);
	sfConvexShape_setFillColor(shape, get_shadow(shape));
	sfConvexShape_setOutlineThickness(shape, 2);
	sfConvexShape_setOutlineColor(shape, sfBlack);
	sfRenderWindow_drawConvexShape(wd->window, shape, NULL);
	sfConvexShape_destroy(shape);
	return (0);
}

int draw_2d_map(world_t *wd, object_t *obj_arr)
{
	int x = 0;
	int y = 0;

	while (y < MAP_Y - 1) {
		while (x < MAP_X - 2) {
			draw_shape(wd, obj_arr, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
