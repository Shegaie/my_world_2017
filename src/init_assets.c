/*
** EPITECH PROJECT, 2017
** File Name : init_assets.c
** File description:
** Rémi BISSON
*/
#include "my.h"

int init_background(object_t *bg)
{
	bg->texture = sfTexture_createFromFile(BG_PATH, NULL);
	bg->sprite = sfSprite_create();
	sfSprite_setTexture(bg->sprite, bg->texture, sfTrue);
	return (0);
}

int init_left_arrow(object_t *left_arrow)
{
	sfVector2f left_arrow_pos;
	sfVector2f arrow_scale;

	left_arrow_pos.x = 370;
	left_arrow_pos.y = 70;
	arrow_scale.x = 0.3;
	arrow_scale.y = 0.3;
	left_arrow->texture = sfTexture_createFromFile(LEFT_ARROW_PATH, NULL);
	left_arrow->sprite = sfSprite_create();
	sfSprite_setTexture(left_arrow->sprite, left_arrow->texture, sfTrue);
	sfSprite_setPosition(left_arrow->sprite, left_arrow_pos);
	sfSprite_setScale(left_arrow->sprite, arrow_scale);
	return (0);
}

int init_right_arrow(object_t *right_arrow)
{
	sfVector2f right_arrow_pos;
	sfVector2f arrow_scale;

	arrow_scale.x = 0.3;
	arrow_scale.y = 0.3;
	right_arrow_pos.x = 500;
	right_arrow_pos.y = 70;
	right_arrow->texture = sfTexture_createFromFile(RIGHT_ARROW_PATH, NULL);
	right_arrow->sprite = sfSprite_create();
	sfSprite_setTexture(right_arrow->sprite, right_arrow->texture, sfTrue);
	sfSprite_setPosition(right_arrow->sprite, right_arrow_pos);
	sfSprite_setScale(right_arrow->sprite, arrow_scale);
	return (0);
}

int init_toolbar(object_t *toolbar)
{
 	sfVector2f toolbar_pos;

	toolbar_pos.x = 100;
	toolbar_pos.y = 50;
	toolbar->texture = sfTexture_createFromFile(TOOLBAR_PATH, NULL);
	toolbar->sprite = sfSprite_create();
	sfSprite_setTexture(toolbar->sprite, toolbar->texture, sfTrue);
	sfSprite_setPosition(toolbar->sprite, toolbar_pos);
	return (0);
}

int init_tile(object_t *tile)
{
	tile->texture = sfTexture_createFromFile(TEXTURE_PATH, NULL);
	tile->sprite = NULL;
	return (0);
}
