/*
** gere.c for gere in /home/dewulf_f//afs/Igraph/fdf
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon Dec  5 13:15:24 2011 florian dewulf
** Last update Mon Jan 16 15:33:04 2012 Florian Dewulf
*/

#include <math.h>
#include <stdlib.h>
#include "../minilibx/mlx.h"
#include "header.h"

int	gere_expose(t_mlx **p)
{
  mlx_put_image_to_window((*p)->mlx_ptr, (*p)->win_ptr, (*p)->img, 0, 0);
  return (0);
}

void	reduckey(int key, t_mlx **s)
{
  float	y;
  float	x;

  if (key == UP || key == 'z')
    {
      y = sinf(((*s)->perso)->angle) * 0.1 * (*s)->speed;
      x = cosf(((*s)->perso)->angle) * 0.1 * (*s)->speed;
      if ((*s)->tab[(int) ((*s)->perso->y0 - y)]
	  [(int) ((*s)->perso->x0 - x)] != '1')
	{
	  ((*s)->perso)->x0 -= cosf(((*s)->perso)->angle) * 0.1 * (*s)->speed;
	  ((*s)->perso)->y0 -= sinf(((*s)->perso)->angle) * 0.1 * (*s)->speed;
	}
    }
  if (key == DOWN || key == 's')
    {
      y = sinf(((*s)->perso)->angle) * 0.1;
      x = cosf(((*s)->perso)->angle) * 0.1;
      if ((*s)->tab[(int) ((*s)->perso->y0 + y)]
	  [(int) ((*s)->perso->x0 + x)] != '1')
	{
	  ((*s)->perso)->x0 += cosf(((*s)->perso)->angle) * 0.1 * (*s)->speed;
	  ((*s)->perso)->y0 += sinf(((*s)->perso)->angle) * 0.1 * (*s)->speed;
	}
    }
}

void	reduckeytwo(int key, t_mlx **s)
{
  int	i;

  i = 0;
  if (key == 65307)
    {
      while ((*s)->tab[i++] != NULL);
      i--;
      while (i >= 0)
	free((*s)->tab[i--]);
      free((*s)->tab);
      exit(EXIT_FAILURE);
    }
  if (key == RIGHT || key == 'd')
    ((*s)->perso)->angle -= 0.02 * (*s)->speed;
  if (key == LEFT || key == 'q')
    ((*s)->perso)->angle += 0.02 * (*s)->speed;
  if (key == 'v')
    {
      (*s)->speed *= 2;
      if ((*s)->speed == 8)
	(*s)->speed = 1;
    }
}

int	gere_key(int keycode, t_mlx **s)
{
  int		i;
  t_mlx		*tmp;

  i = 0;
  tmp = (*s);
  reduckey(keycode, &tmp);
  reduckeytwo(keycode, &tmp);
  tmp = put_sol_and_sky(tmp);
  calcul(&tmp);
  cadre(&tmp);
  map(&tmp);
  viseur(&tmp);
  weapon(&tmp);
  pos_map(&tmp);
  (*s) = tmp;
  mlx_put_image_to_window(tmp->mlx_ptr, tmp->win_ptr, tmp->img, 0, 0);
  return (0);
}

int	gere_mouse(int button, int x, int y, t_mlx **p)
{
  int	i;
  int	j;
  t_mlx	*tmp;

  i = (int) ((x - WINX_RAY) / (200 / my_strlen((*p)->tab[0])));
  j = (int) ((y - WINY_RAY) / (200 / my_strlen((*p)->tab[0])));
  if (button == 1 && i < (my_strlen((*p)->tab[0]) - 1) &&
      j < (my_strlen((*p)->tab[0]) - 2) && i > 0 && j > 0)
    {
      if ((*p)->tab[j][i] == '1')
	(*p)->tab[j][i] = '0';
      else if ((*p)->tab[j][i] == '0')
	(*p)->tab[j][i] = '1';
      tmp = (*p);
      tmp = put_sol_and_sky(tmp);
      calcul(&tmp);
      cadre(&tmp);
      map(&tmp);
      viseur(&tmp);
      weapon(&tmp);
      pos_map(&tmp);
      (*p) = tmp;
      mlx_put_image_to_window(tmp->mlx_ptr, tmp->win_ptr, tmp->img, 0, 0);
    }
  return (0);
}
