/*
** EPITECH PROJECT, 2018
** draw_stat.c
** File description:
** print the stat
*/
#include "my.h"

int init_font(world_t *wd)
{
	sfVector2f actz_pos;

	actz_pos.x = 454;
	actz_pos.y = 73;
	wd->mouv.actz_txt = sfText_create();
	wd->mouv.actz_ft = sfFont_createFromFile(FONT_PATH);
	sfText_setFont(wd->mouv.actz_txt, wd->mouv.actz_ft);
	sfText_setCharacterSize(wd->mouv.actz_txt, 45);
	sfText_setPosition(wd->mouv.actz_txt, actz_pos);
	return (0);
}

int draw_stat(world_t *wd,
	__attribute__((unused)) object_t *obj_arr)
{
	char *actz_str;

	actz_str = malloc(sizeof(char) * 2);
	actz_str[0] = wd->mouv.actionz + '0';
	actz_str[1] = '\0';

	sfText_setString(wd->mouv.actz_txt, actz_str);
	sfRenderWindow_drawText(wd->window, wd->mouv.actz_txt, NULL);
	return (0);
}
