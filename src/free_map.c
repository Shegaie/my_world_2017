/*
** EPITECH PROJECT, 2017
** File Name : free_map.c
** File description:
** Rémi BISSON
*/
#include "my.h"

int free_map(world_t *wd)
{
	for (int i = 0; i < MAP_Y; i++)
		free(wd->map.map3d[i]);
	free(wd->map.map3d);
	for (int i = 0; i < MAP_Y; i++)
		free(wd->map.map2d[i]);
	free(wd->map.map2d);
	return (0);
}
