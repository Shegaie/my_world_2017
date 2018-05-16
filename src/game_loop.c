/*
** EPITECH PROJECT, 2017
** File Name : game_loop.c
** File description:
** Rémi BISSON
*/
#include "my.h"

int game_loop(world_t *wd)
{
	object_t *obj_arr = fill_obj_arr();

	init_font(wd);
	fill_map3d(wd);
	while (sfRenderWindow_isOpen(wd->window)) {
		sfRenderWindow_clear(wd->window, sfBlack);
		if (analyse_events(wd, obj_arr) == 1)
			break;
		coord_map(wd);
		draw_background(wd, obj_arr);
		draw_2d_map(wd, obj_arr);
		draw_toolbar(wd, obj_arr);
		draw_stat(wd, obj_arr);
		while (sfKeyboard_isKeyPressed(sfKeyH) == sfTrue) {
			draw_manual(wd, obj_arr);
		}
		sfRenderWindow_display(wd->window);
	}
	destroy_objects(wd, obj_arr);
	return (0);
}
