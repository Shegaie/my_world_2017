/*
** EPITECH PROJECT, 2017
** File Name : events.c
** File description:
** Rémi BISSON
*/
#include "my.h"

int analyse_events(world_t * wd, object_t * obj_arr)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(wd->window, &event)) {
		mouse_click(event, wd, obj_arr);
		mouse_scroll(event, wd);
		keyboard_inputs(event, wd, obj_arr);
		if (event.key.code == sfKeyK)
			return((disp_code(wd, obj_arr) == 1) ? (1) : (0));
	}
	return (0);
}
