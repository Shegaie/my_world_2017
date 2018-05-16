/*
** EPITECH PROJECT, 2017
** File Name : keyboard_inputs.c
** File description:
** Rémi BISSON
*/
#include "my.h"
#include "time.h"

int moving_map_inputs(sfEvent event, world_t *wd)
{
	if (event.key.code == sfKeyD)
		wd->cam.mouv_x -= MAP_X / 20;
	if (event.key.code == sfKeyQ)
		wd->cam.mouv_x += MAP_X / 20;
	if (event.key.code == sfKeyZ)
		wd->cam.mouv_y += MAP_Y / 20;
	if (event.key.code == sfKeyS)
		wd->cam.mouv_y -= MAP_Y / 20;
	return (0);
}

int incline_map_inputs(sfEvent event, world_t *wd)
{
	if (event.key.code == sfKeyDown)
		wd->cam.incline_y -= 0.1;
	if (event.key.code == sfKeyUp)
		wd->cam.incline_y += 0.1;
	return (0);
}

int reset_map_inputs(sfEvent event, world_t *wd)
{
	int i = 0;
	sfVector2i pos;

	if (event.key.code == sfKeySpace && wd->mouv.space_mode == 0)
		fill_map3d(wd);
	if (event.key.code == sfKeySpace && wd->mouv.space_mode == 1) {
		fill_map3d(wd);
		while (i != 100) {
			pos.x = rand() % MAP_X;
			pos.y = rand() % MAP_Y;
			wd->map.map3d[pos.y][pos.x] += 1;
			smooth(pos, wd);
			i++;
		}
	}
	return (0);
}

int draw_manual(world_t *wd,  object_t *obj_arr)
{
	object_t man;

	sfRenderWindow_clear(wd->window, sfBlack);
	man.texture = sfTexture_createFromFile(MAN_PATH, NULL);
	man.sprite = sfSprite_create();
	sfSprite_setTexture(man.sprite, man.texture, sfTrue);
	draw_background(wd, obj_arr);
	draw_2d_map(wd, obj_arr);
	draw_toolbar(wd, obj_arr);
	draw_stat(wd, obj_arr);
	sfRenderWindow_drawSprite(wd->window, man.sprite, NULL);
	sfRenderWindow_display(wd->window);
	sfSprite_destroy(man.sprite);
	sfTexture_destroy(man.texture);
	return (0);
}

int keyboard_inputs(sfEvent event, world_t *wd,
		__attribute__((unused)) object_t *obj_arr)
{
	if (event.type == sfEvtKeyPressed) {
		if (event.key.code == sfKeyEscape)
			sfRenderWindow_close(wd->window);
		moving_map_inputs(event, wd);
		incline_map_inputs(event, wd);
		reset_map_inputs(event, wd);
	}
	return (0);
}
