/*
** EPITECH PROJECT, 2017
** File Name : destroy_objects.c
** File description:
** Rémi BISSON
*/
#include "my.h"

int destroy_objects(world_t *wd, object_t *obj_arr)
{
	for (int i = 0; i < NB_ASSETS; i++) {
		if (obj_arr[i].sprite != NULL)
			sfSprite_destroy(obj_arr[i].sprite);
		if (obj_arr[i].texture != NULL)
			sfTexture_destroy(obj_arr[i].texture);
	}
	free(obj_arr);
	free_map(wd);
	sfClock_destroy(wd->clock.clock);
	sfRenderWindow_destroy(wd->window);
	return (0);
}
