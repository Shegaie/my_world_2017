##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Rémi BISSON
##
SRC_DIR	=	$(realpath src)/
INC	=	$(realpath include)/
SRC	=	$(SRC_DIR)destroy_objects.c	\
		$(SRC_DIR)events.c		\
		$(SRC_DIR)game_loop.c		\
		$(SRC_DIR)main.c		\
		$(SRC_DIR)map_create.c	  	\
		$(SRC_DIR)open_window.c		\
		$(SRC_DIR)special_malloc.c	\
		$(SRC_DIR)draw_map.c		\
		$(SRC_DIR)manip_map.c		\
		$(SRC_DIR)free_map.c		\
		$(SRC_DIR)init.c		\
		$(SRC_DIR)mouse_click.c		\
		$(SRC_DIR)mouse_scroll.c	\
		$(SRC_DIR)keyboard_inputs.c	\
		$(SRC_DIR)draw_toolbar.c	\
		$(SRC_DIR)obj_array.c		\
		$(SRC_DIR)init_assets.c		\
		$(SRC_DIR)around_point.c	\
		$(SRC_DIR)draw_stat.c		\
		$(SRC_DIR)init_assets2.c	\
		$(SRC_DIR)diskonami.c		\
		$(SRC_DIR)diskonami_input.c
OBJ	=	$(SRC:.c=.o)
NAME	=	my_world
CFLAGS +=	-Wall -W -Wextra -I$(INC)
CFLAGS +=	-lc_graph_prog -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all clean
