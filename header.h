/*
** header.h for header in /home/dewulf_f//afs/Igraph/fdf
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon Dec  5 13:17:38 2011 florian dewulf
** Last update Sun Jan 15 11:45:23 2012 florian dewulf
*/

#ifndef __HEADER_H__
#define __HEADER_H__

#include "list.h"

#define		DOWN		65364
#define		UP		65362
#define		RIGHT		65363
#define		LEFT		65361

#define		WINX		1000
#define		WINY		1000

#define		WINX_RAY	800
#define		WINY_RAY	800

#define		D		1
#define		P		0.7

#define		MVT		0.01

//func.c

void	my_putchar(char);
int	my_putstr(char *);
int	my_strlen(char *);
void	*xmalloc(int);

//func bis

char	*get_plus_copy(char *, char *, int, int);
void	put_color(t_mlx **, int, int);
void	draw_verti2(t_mlx **, int);

//gere.c

int	gere_expose(t_mlx **);
int	gere_key(int, t_mlx **);
int	gere_mouse(int, int, int, t_mlx **);

//sol_sky.c

t_mlx	*put_wall(t_mlx *);
t_mlx	*put_sol_and_sky(t_mlx *);

char	**to_tab(int);

#endif
