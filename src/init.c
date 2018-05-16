/*
** EPITECH PROJECT, 2017
** File Name : init.c
** File description:
** Rémi BISSON
*/
#include "my.h"

int init_values(world_t *wd)
{
	sfRenderWindow *window_pnt;

	window_pnt = open_window();
	wd->window = window_pnt;
	wd->map.mode = UP;
	wd->map.map2d = malloc_2dmap();
	wd->cam.zoom = 1;
	wd->cam.incline_y = 0.30;
	wd->cam.mouv_x = 0;
	wd->cam.mouv_y = 0;
	wd->mouv.hitbox = HITBOX;
	wd->mouv.actionz = ACTIONZ;
	wd->mouv.space_mode = 0;
	wd->clock.clock = sfClock_create();
	return (0);
}
