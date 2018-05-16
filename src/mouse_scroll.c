/*
** EPITECH PROJECT, 2017
** File Name : mouse_scroll.c
** File description:
** Rémi BISSON
*/
#include "my.h"

int mouse_scroll(sfEvent event, world_t *wd)
{
	if (event.type == sfEvtMouseWheelScrolled) {
		wd->cam.zoom += event.mouseWheelScroll.delta/10;
	}
	return (0);
}
