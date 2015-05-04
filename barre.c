/*
** boussole.c for wolf3d in /home/dewulf_f//afs/wolf3d-2016-dewulf_f
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Sun Jan 15 19:30:29 2012 florian dewulf
** Last update Sun Jan 15 19:59:40 2012 florian dewulf
*/

#include "header.h"

void	life(t_coord *pos, t_mlx ***tmp, int color)
{
  int	x;
  int	res;
  t_mlx	**s;
  int	col;

  s = (*tmp);
  col = color;
  while (pos->c_y < pos->c_ym)
    {
      x = pos->c_x;
      color = col;
      while (x < pos->c_xm)
	{
	  res = x * 4 + (WINX * 4 * pos->c_y);
	  (*s)->data[res++] = 0;
	  (*s)->data[res++] = 0;
	  (*s)->data[res++] = color;
	  (*s)->data[res] = 0;
	  x++;
	  if (x % 3 == 0)
	    color--;
	}
      pos->c_y++;
    }
  (*tmp) = s;
}
void	life_green(t_coord *pos, t_mlx ***tmp, int color)
{
  int	x;
  int	res;
  t_mlx	**s;
  int	col;

  s = (*tmp);
  col = color;
  while (pos->c_y < pos->c_ym)
    {
      x = pos->c_x;
      color = col;
      while (x < pos->c_xm)
	{
	  res = x * 4 + (WINX * 4 * pos->c_y);
	  (*s)->data[res++] = 0;
	  (*s)->data[res++] = color;
	  (*s)->data[res++] = 0;
	  (*s)->data[res] = 0;
	  x++;
	  if (x % 3 == 0)
	    color--;
	}
      pos->c_y++;
    }
  (*tmp) = s;
}

void	life_blue(t_coord *pos, t_mlx ***tmp, int color)
{
  int	x;
  int	res;
  t_mlx	**s;
  int	col;

  s = (*tmp);
  col = color;
  while (pos->c_y < pos->c_ym)
    {
      x = pos->c_x;
      color = col;
      while (x < pos->c_xm)
	{
	  res = x * 4 + (WINX * 4 * pos->c_y);
	  (*s)->data[res++] = color;
	  (*s)->data[res++] = 0;
	  (*s)->data[res++] = 0;
	  (*s)->data[res] = 0;
	  x++;
	  if (x % 3 == 0)
	    color--;
	}
      pos->c_y++;
    }
  (*tmp) = s;
}

void	usure(t_mlx **s)
{
  t_coord	point;
  int		color;

  color = 200;
  point.c_x = 100;
  point.c_xm = WINX_RAY - 100;
  point.c_y = WINY_RAY + 25;
  point.c_ym = point.c_y + 30;
  life(&point, &s, color);
  point.c_x = 100;
  point.c_xm = WINX_RAY - 100;
  point.c_y = WINY_RAY + 65;
  point.c_ym = point.c_y + 30;
  life_blue(&point, &s, color);
  point.c_x = 100;
  point.c_xm = WINX_RAY - 100;
  point.c_y = WINY_RAY + 105;
  point.c_ym = point.c_y + 30;
  life_green(&point, &s, color);
}
