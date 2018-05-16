/*
** EPITECH PROJECT, 2017
** File Name : mouse_click.c
** File description:
** Rémi BISSON
*/
#include "my.h"
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <time.h>

int button_click(sfEvent *event,
		__attribute__((unused))object_t *obj_arr, world_t *wd)
{
	if (event->mouseButton.x > 366 && event->mouseButton.x < 366+62
	&& event->mouseButton.y > 67 && event->mouseButton.y < 67+64) {
		if (wd->mouv.actionz > 1)
			wd->mouv.actionz--;
	}
	if (event->mouseButton.x > 498 && event->mouseButton.x < 498+62
	&& event->mouseButton.y > 67 && event->mouseButton.y < 67+64) {
		if (wd->mouv.actionz < 9)
			wd->mouv.actionz++;
	}
	if (event->mouseButton.x > 260 && event->mouseButton.x < 260+64
	&& event->mouseButton.y > 64 && event->mouseButton.y < 64+68) {
		((wd->mouv.space_mode == 0) ? (wd->mouv.space_mode = 1)
		: (wd->mouv.space_mode = 0));
	}
	return (0);
}

int mouse_click(sfEvent event, world_t *wd,
		__attribute__((unused))object_t *obj_arr)
{
	if (event.type == sfEvtMouseButtonPressed) {
		if (event.mouseButton.button == sfMouseLeft) {
			button_click(&event, obj_arr, wd);
			manip_map(&event, wd);
		}
		if (event.mouseButton.button == sfMouseRight) {
			if (wd->map.mode == UP)
				wd->map.mode = DOWN;
			else if (wd->map.mode == DOWN)
				wd->map.mode = UP;
		}
	}
	return (0);
}
