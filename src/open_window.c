/*
** EPITECH PROJECT, 2017
** File Name : open_window.c
** File description:
** Rémi BISSON
*/
#include "my.h"
#include "open_window.h"

sfRenderWindow* open_window(void)
{
	sfVideoMode mode = {WIDTH, HEIGHT, BITSPERPIXELS};
	sfRenderWindow* window;

	window = sfRenderWindow_create(mode, TITLE, sfResize | sfClose
				| sfFullscreen , NULL);
	if (window == NULL)
		return (NULL);
	sfRenderWindow_setFramerateLimit(window, 60);
	return (window);
}
