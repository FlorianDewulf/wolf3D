/*
** calcul.c for calcul.c in /home/dewulf_f//afs/Igraph/Wolf/Dossier_propre
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon Jan  9 22:33:06 2012 florian dewulf
** Last update Sun Jan 15 19:00:44 2012 florian dewulf
*/

#include <math.h>
#include "header.h"

void	reduc_col(t_mlx ***tmp, int i, float k, int color)
{
  t_mlx	**s;
  int	y1;
  int	r;
  int	size;

  size = (WINY / (2 * k)) / 2;
  y1 = ((WINY_RAY / 2) - size);
  size = ((WINY_RAY / 2) + size);
  s = (*tmp);
  put_the_limit(&s, y1, i);
  y1++;
  while (y1++ < size)
    put_the_tron(&s, i, y1, color);
  put_the_limit(&s, y1, i);
}

void	put_col(float k, int i, t_mlx **s, int ret)
{
  int	y1;

  if (k > 0.63)
    reduc_col(&s, i, k, ret);
  else
    {
      y1 = -1;
      while (++y1 < WINY_RAY)
	put_the_tron(&s, i, y1, ret);
    }
}

int	check_wall(float x, float y)
{
  int	xint_tmp;
  int	yint_tmp;

  xint_tmp = x;
  yint_tmp = y;
  x -= xint_tmp;
  y -= yint_tmp;
  xint_tmp = x * 100000;
  yint_tmp = y * 100000;
  if (xint_tmp >= yint_tmp)
    return (1);
  else
    return (2);
}

t_mlx	**calc_intersection(int i, float x1, float y1, t_mlx **s)
{
  float	x0;
  float	y0;
  float	k;
  t_mlx	*tr;
  float	x;
  float	y;
  int	ret;

  k = 0;
  tr = (*s);
  x0 = (*s)->perso->x0;
  y0 = (*s)->perso->y0;
  while (tr->tab[(int) (y0 + k * (y0 - y1))][(int) (x0 + k * (x0 - x1))] != '1')
    k += 0.01;
  x = x0 + k * (x0 - x1);
  y = y0 + k * (y0 - y1);
  ret = check_wall(x, y);
  put_col(k, i, &tr, ret);
  (*s) = tr;
  return (s);
}

void	calcul(t_mlx **s)
{
  int		i;  
  float		x1;
  float		y1;
  float		y;

  i = 0;
  while (i < WINX_RAY)
    {
      y = (P / WINX) * ((WINX / 2) - i);
      x1 = D * cosf(((*s)->perso)->angle) - y * sinf(((*s)->perso)->angle);
      x1 += ((*s)->perso)->x0;
      y1 = D * sinf(((*s)->perso)->angle) + y * cosf(((*s)->perso)->angle);
      y1 += ((*s)->perso)->y0;
      s = calc_intersection(i, x1, y1, s);
      i++;
    }
}
