/*
** EPITECH PROJECT, 2018
** diskonami.c
** File description:
** secret option
*/

#include "my.h"
int draw_disco(world_t * wd,
	       __attribute__ ((unused)) object_t * obj_arr, int x, int y)
{
	sfConvexShape *shape = sfConvexShape_create();
	sfColor color_rand;

	color_rand.r = rand() % 255;
	color_rand.g = rand() % 255;
	color_rand.b = rand() % 255;
	color_rand.a = 255;
	if (shape == NULL)
		return (-1);
	sfConvexShape_setPointCount(shape, 4);
	sfConvexShape_setPoint(shape, 0, wd->map.map2d[y][x]);
	sfConvexShape_setPoint(shape, 1, wd->map.map2d[y][x + 1]);
	sfConvexShape_setPoint(shape, 2, wd->map.map2d[y + 1][x + 1]);
	sfConvexShape_setPoint(shape, 3, wd->map.map2d[y + 1][x]);
	sfConvexShape_setFillColor(shape, color_rand);
	sfRenderWindow_drawConvexShape(wd->window, shape, NULL);
	sfConvexShape_destroy(shape);
	return (0);
}

int draw_disco_map(world_t * wd, __attribute__ ((unused)) object_t * obj_arr)
{
	int x = 0;
	int y = 0;

	while (y < MAP_Y - 1) {
		while (x < MAP_X - 2) {
			draw_disco(wd, obj_arr, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int draw_background2(world_t * wd, __attribute__ ((unused)) object_t * obj_arr)
{
	object_t bg2;

	bg2.texture = sfTexture_createFromFile("assets/bg2.png", NULL);
	bg2.sprite = sfSprite_create();
	sfSprite_setTexture(bg2.sprite, bg2.texture, sfTrue);
	sfRenderWindow_drawSprite(wd->window, bg2.sprite, NULL);
        sfSprite_destroy(bg2.sprite);
	sfTexture_destroy(bg2.texture);
	return (0);
}

int analyse_events_disco(world_t * wd, object_t * obj_arr, sfMusic * music)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(wd->window, &event)) {
		if (event.key.code == sfKeyEscape) {
			sfMusic_destroy(music);
			return (1);
		}
		mouse_click(event, wd, obj_arr);
		mouse_scroll(event, wd);
		keyboard_inputs(event, wd, obj_arr);
	}
	return (0);
}

int diskonami(world_t * wd, object_t * obj_arr)
{
	sfMusic *music;

	music = sfMusic_createFromFile("assets/sh_st.ogg");
	sfMusic_play(music);
	while (sfKeyboard_isKeyPressed(sfKeyL) == sfFalse) {
		sfRenderWindow_clear(wd->window, sfBlack);
		if (analyse_events_disco(wd, obj_arr, music) == 1)
			return (1);
		coord_map(wd);
		draw_background2(wd, obj_arr);
		draw_disco_map(wd, obj_arr);
		sfRenderWindow_display(wd->window);
	}
	sfMusic_destroy(music);
	return (0);
}
