/*
** EPITECH PROJECT, 2017
** File Name : my.h
** File description:
** Rémi BISSON
*/
#ifndef MY_H
#define MY_H

#include <time.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "macro.h"
#include "struct.h"

int analyse_events(world_t *wd, object_t *obj_arr);
int around_point(int i, sfVector2i pos, world_t *wd);
int coord_map(world_t *wd);
int diskonami(world_t *wd, object_t *obj_arr);
int draw_background(world_t *wd, object_t *obj_arr);
int draw_toolbar(world_t *wd, object_t *obj_arr);
int draw_2d_map(world_t *wd, object_t *obj_arr);
int draw_actionz(world_t *wd, object_t *obj_arr);
int draw_manual(world_t *wd, object_t *obj_arr);
int destroy_objects(world_t *wd, object_t *obj_arr);
int disp_code(world_t * wd, object_t * obj_arr);
int draw_stat(world_t *wd, object_t *obj_arr);
int *fill_code(int *code);
int fill_map3d(world_t *wd);
object_t *fill_obj_arr(void);
int fill_obj_arr2(object_t *obj_arr);
int free_map(world_t *wd);
sfRenderWindow *open_window(void);
int game_loop(world_t *wd);
sfVector2f project_iso_point(int x, int y, world_t *wd);
sfVector2f **malloc_2dmap();
int incline_map_inputs(sfEvent event, world_t *wd);
int increase_up_down(int i, sfVector2i pos, world_t * wd, int tmp);
int increase_border(int i, sfVector2i pos, world_t * wd, int tmp);
int init_font(world_t *wd);
int init_background(object_t *bg);
int init_left_arrow(object_t *left_arrow);
int init_right_arrow(object_t *right_arrow);
int init_tile(object_t *tile);
int init_toolbar(object_t *toolbar);
int init_switch_p(object_t *switch_p);
int init_values(world_t *wd);
int is_konami_realise(int *t_c, int *code);
int keyboard_inputs(sfEvent event, world_t *wd, object_t *obj_arr);
int konami_code(world_t * wd);
sfColor get_shadow(sfConvexShape *shape);
int malloc_2d_array(world_t *wd);
int manip_map(sfEvent *event, world_t *wd);
int mouse_click(sfEvent event, world_t *wd, object_t *obj_arr);
int mouse_scroll(sfEvent event, world_t *wd);
int moving_map_inputs(sfEvent event, world_t *wd);
int reset_map_inputs(sfEvent event, world_t *wd);
int smooth(sfVector2i pos, world_t *wd);
sfVector2i which_point(sfEvent * event, world_t *wd);
int *which_key(int *t_c, int i, sfEvent event);

#endif
