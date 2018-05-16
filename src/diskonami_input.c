/*
** EPITECH PROJECT, 2018
** diskonami_input.c
** File description:
** verifie if you type konami code
*/

#include "my.h"

int *fill_code(int *code)
{
	code[0] = 1;
	code[1] = 1;
	code[2] = 2;
	code[3] = 2;
	code[4] = 3;
	code[5] = 4;
	code[6] = 3;
	code[7] = 4;
	code[8] = 5;
	code[9] = 6;
	return (code);
}

int *which_key(int *t_c, int i, sfEvent event)
{
	if (event.key.code == sfKeyUp)
		t_c[i] = 1;
	if (event.key.code == sfKeyDown)
		t_c[i] = 2;
	if (event.key.code == sfKeyLeft)
		t_c[i] = 3;
	if (event.key.code == sfKeyRight)
		t_c[i] = 4;
	if (event.key.code == sfKeyB)
		t_c[i] = 5;
	if (event.key.code == sfKeyA)
		t_c[i] = 6;
	return (t_c);
}

int is_konami_realise(int *t_c, int *code)
{
	int i = 0;

	while (t_c[i] == code[i] && i < 10) {
		i++;
	}
	if (i == 10)
		return (1);
	else
		return (0);
}

int konami_code(world_t * wd)
{
	int *t_c;
	int *code;
	int i = 0;
	sfEvent event;

	code = malloc(sizeof(int) * 10);
	t_c = malloc(sizeof(int) * 10);
	code = fill_code(code);
	while (1) {
		while (sfRenderWindow_pollEvent(wd->window, &event)) {
			if (event.type == sfEvtKeyPressed) {
				t_c = which_key(t_c, i, event);
				i++;
			}
		}
		if (i == 10)
			break;
	}
	if (is_konami_realise(t_c, code) == 1)
		return (1);
	else
		return (0);
}

int disp_code(world_t * wd, object_t * obj_arr)
{
	object_t code_p;

	code_p.texture = sfTexture_createFromFile("assets/code.png", NULL);
	code_p.sprite = sfSprite_create();
	sfSprite_setTexture(code_p.sprite, code_p.texture, sfTrue);
	while (1) {
		sfRenderWindow_clear(wd->window, sfBlack);
		draw_background(wd, obj_arr);
		draw_2d_map(wd, obj_arr);
		draw_toolbar(wd, obj_arr);
		draw_stat(wd, obj_arr);
		sfRenderWindow_drawSprite(wd->window, code_p.sprite, NULL);
		sfRenderWindow_display(wd->window);
		if (konami_code(wd) == 1)
			return((diskonami(wd, obj_arr) == 1) ? (1) : (0));
		else
			return (0);
	}
	return (0);
}
