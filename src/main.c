/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** Rémi BISSON
*/
#include "my.h"

int main(int __attribute__((unused)) ac,
	char __attribute__((unused)) **av, char **ae)
{
	world_t wd;
	if (ae[0] == NULL) {
		write(1, "Missing environment\n", 20);
		return (84);
	}
	init_values(&wd);
	game_loop(&wd);
	return (0);
}
