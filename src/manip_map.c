/*
** EPITECH PROJECT, 2018
** manip_map.c
** File description:
** manipulate map
*/
#include "my.h"
#include "open_window.h"

int is_in_hitbox(sfEvent * event, world_t *wd, int a, int i)
{
	if (event->mouseButton.x > wd->map.map2d[a][i].x
	- wd->mouv.hitbox
	&& event->mouseButton.x < wd->map.map2d[a][i].x
	+ wd->mouv.hitbox
	&& event->mouseButton.y > wd->map.map2d[a][i].y
	- wd->mouv.hitbox
	&& event->mouseButton.y < wd->map.map2d[a][i].y
	+ wd->mouv.hitbox)
		return (0);
	return (-1);
}

sfVector2i which_point(sfEvent * event, world_t *wd)
{
	int a = MAP_Y-1;
	int i = MAP_X-1;
	sfVector2i pos;

	while (a >= 0) {
		while (i >= 0) {
			if (is_in_hitbox(event, wd, a, i) == 0) {
				pos.x = i;
				pos.y = a;
				return (pos);
			}
			i--;
		}
		a--;
		i = MAP_X-1;
	}
	pos.x = -1;
	pos.y = -1;
	return (pos);
}

int smooth(sfVector2i pos, world_t *wd)
{
	int i = 1;

	while (i != wd->mouv.actionz) {
		around_point(i, pos, wd);
		i++;
	}
	return (0);
}

int manip_map(sfEvent * event, world_t *wd)
{
	sfVector2i pos = which_point(event, wd);

	if (pos.x != -1 && wd->map.mode == UP) {
		wd->map.map3d[pos.y][pos.x] += 1;
		smooth(pos, wd);
	}
	else if (pos.x != -1 && wd->map.mode == DOWN) {
		wd->map.map3d[pos.y][pos.x] -= 1;
		smooth(pos, wd);
	}
	return (0);
}
