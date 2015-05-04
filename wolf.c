/*
** tp1_windows_empty.c for tp1_windows_empty in /home/dewulf_f//afs/Igraph/TP1
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon Nov  7 15:31:02 2011 florian dewulf
** Last update Fri Mar 30 12:48:38 2012 florian dewulf
*/

#include <unistd.h>
#include <stdlib.h>
#include <X11/X.h>
#include <math.h>
#include <mlx.h>
#include "header.h"
#include "get_next_line.h"
#include "list.h"

void	boucle(int a, int b)
{
  t_point	*pos;
  t_mlx		*st;

  st->mlx_ptr = mlx_init();
  if (st->mlx_ptr == NULL)
    exit(my_putstr("Fail execution (Pas d'environnement)\n"));
  st->win_ptr = mlx_new_window(st->mlx_ptr, 1000, 1000, "Wolf");
  st->img = mlx_new_image(st->mlx_ptr, 1000, 1000);
  st->data = mlx_get_data_addr(st->img, &st->bpp, &st->size, &st->endian);
  st->tab = to_tab(a);
  pos = xmalloc(sizeof(t_point));
  (st->perso = pos) ? (pos->angle = 3.14) : (pos->angle = 3.14);
  (pos->x0 = 1.5) ? (pos->y0 = pos->x0) : (pos->y0 = pos->x0);
  (st = put_sol_and_sky(st)) ? (st->speed = 1) : (st->speed = 1);
  calcul(&st);
  cadre(&st);
  map(&st);
  viseur(&st);
  (st->sword = to_tab(b)) ? usure(&st) : usure(&st);
  weapon(&st);
  pos_map(&st);
  mlx_expose_hook(st->win_ptr, gere_expose, &st);
  mlx_mouse_hook(st->win_ptr, gere_mouse, &st);
  mlx_hook(st->win_ptr, KeyPress, KeyPressMask, gere_key, &st);
  mlx_loop(st->mlx_ptr);
}
