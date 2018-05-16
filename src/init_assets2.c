/*
** EPITECH PROJECT, 2018
** init_asset.c
** File description:
** init the asset
*/

#include "my.h"

int init_switch_p(object_t *switch_p)
{
	sfVector2f switch_pos;
	sfVector2f switch_scale;

	switch_pos.x = 170;
	switch_pos.y = -17;
	switch_scale.x = 1.2;
	switch_scale.y = 1.2;
	switch_p->texture = sfTexture_createFromFile(SWITCH_PATH, NULL);
	switch_p->sprite = sfSprite_create();
	sfSprite_setTexture(switch_p->sprite, switch_p->texture, sfTrue);
	sfSprite_setPosition(switch_p->sprite, switch_pos);
	sfSprite_setScale(switch_p->sprite, switch_scale);
	return (0);
}
