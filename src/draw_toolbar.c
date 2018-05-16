/*
** EPITECH PROJECT, 2018
** draw_toolbar.c
** File description:
** draw toolbar
*/
#include "my.h"

int draw_background(world_t *wd, object_t *obj_arr)
{
	sfRenderWindow_drawSprite(wd->window, obj_arr[0].sprite, NULL);
	return (0);
}

int draw_toolbar(world_t *wd, object_t *obj_arr)
{
	for (int i = 1; i < NB_ASSETS - 1; i++) {
		sfRenderWindow_drawSprite(wd->window, obj_arr[i].sprite, NULL);
	}
	return (0);
}
