##
## Makefile for Makefile in /home/dewulf_f//afs/Igraph/fdf
## 
## Made by florian dewulf
## Login   <dewulf_f@epitech.net>
## 
## Started on  Mon Dec  5 13:12:27 2011 florian dewulf
## Last update Sun Jan 15 19:48:33 2012 florian dewulf
##

NAME=	wolf3d

SRC=	gere.c \
	wolf.c \
	my_getnbr.c \
	func.c \
	get_next_line.c \
	main.c \
	sol_sky.c \
	to_tab.c \
	func_bis.c \
	calcul.c \
	bonus.c \
	weapon.c \
	pos.c \
	calcul_next.c \
	barre.c

OBJ=	$(SRC:.c=.o)

FLAG=	-L/usr/X11/lib -lmlx_$(HOSTTYPE) -lXext -lX11

CFLAG=	-g -lm

all:	$(OBJ)
	cc -o $(NAME) $(SRC) $(FLAG) $(CFLAG)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re:	fclean all

c:	fclean all
	rm -f $(OBJ)