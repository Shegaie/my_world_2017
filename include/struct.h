/*
** EPITECH PROJECT, 2017
** File Name : struct.h
** File description:
** Rémi BISSON
*/
#ifndef	STRUCT_H
#define STRUCT_H

typedef struct map {
	sfVector2f **map2d;
	float **map3d;
	int mode;
} map_t;

typedef struct camera {
	float zoom;
	float incline_y;
	float incline_x;
	float mouv_x;
	float mouv_y;
} camera_t;

typedef struct button {
	int hitbox;
	int actionz;
	sfText *actz_txt;
	sfFont *actz_ft;
	int space_mode;
	int *code;
} button_t;

typedef struct object {
	sfTexture *texture;
	sfSprite *sprite;
} object_t;

typedef struct clock {
	sfClock *clock;
	sfTime time;
	float seconds;
} clock_m;

typedef struct structures {
	clock_m clock;
	button_t mouv;
	camera_t cam;
	map_t map;
	sfRenderWindow *window;
} world_t;

#endif
