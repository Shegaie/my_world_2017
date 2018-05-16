/*
** EPITECH PROJECT, 2018
** around_point.c
** File description:
** smooth the point and verifie
*/
#include "my.h"

int increase_up_down(int i, sfVector2i pos, world_t * wd, int tmp)
{
	int actz = wd->mouv.actionz;

	if ((pos.y) - i >= 0 && (pos.y) - i < MAP_Y &&
	    (pos.x) + tmp >= 0 && (pos.x) + tmp < MAP_X &&
	    (pos.y) + i >= 0 && (pos.y) + i < MAP_Y) {
		wd->map.map3d[(pos.y) - i][(pos.x) + tmp] +=
			(actz - (float)i) / actz * wd->map.mode;
		wd->map.map3d[(pos.y) + i][(pos.x) + tmp] +=
			(actz - (float)i) / actz * wd->map.mode;
	}
	return (0);
}

int increase_border(int i, sfVector2i pos, world_t * wd, int tmp)
{
	int actz = wd->mouv.actionz;

	if ((pos.y) + tmp >= 0 && (pos.y) + tmp < MAP_Y &&
	    (pos.x) - i >= 0 && (pos.x) - i < MAP_X &&
	    (pos.x) + i >= 0 && (pos.x) + i < MAP_X) {
		wd->map.map3d[(pos.y) + tmp][(pos.x) - i] +=
			(actz - (float)i) / actz * wd->map.mode;
		wd->map.map3d[(pos.y) + tmp][(pos.x) + i] +=
			(actz - (float)i) / actz * wd->map.mode;

	}
	return (0);
}

int around_point(int i, sfVector2i pos, world_t * wd)
{
	int tmp = -i;

	while (tmp <= i) {
		increase_up_down(i, pos, wd, tmp);
		tmp++;
	}
	tmp = -i + 1;
	while (tmp < i) {
		increase_border(i, pos, wd, tmp);
		tmp++;
	}
	return (0);
}
