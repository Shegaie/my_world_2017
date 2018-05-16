/*
** EPITECH PROJECT, 2017
** File Name : obj_array.c
** File description:
** Rémi BISSON
*/
#include "my.h"


int fill_obj_arr2(object_t *obj_arr)
{
	object_t switch_p;

	init_switch_p(&switch_p);
	obj_arr[4] = switch_p;
	return (0);
}

object_t *fill_obj_arr(void)
{
	object_t *obj_arr = malloc(sizeof(object_t) * NB_ASSETS);
	object_t left_arrow;
	object_t right_arrow;
	object_t toolbar;
	object_t tile;
	object_t bg;

	init_background(&bg);
	init_left_arrow(&left_arrow);
	init_right_arrow(&right_arrow);
	init_toolbar(&toolbar);
	init_tile(&tile);
	obj_arr[0] = bg;
	obj_arr[1] = toolbar;
	obj_arr[2] = left_arrow;
	obj_arr[3] = right_arrow;
	obj_arr[5] = tile;
	fill_obj_arr2(obj_arr);
	return (obj_arr);
}
