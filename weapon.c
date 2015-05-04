/*
** weapon.c for wolf in /home/dewulf_f//afs/Igraph/Wolf/Dossier_propre/Propre
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Sun Jan 15 00:30:13 2012 florian dewulf
** Last update Sun Jan 15 11:49:50 2012 florian dewulf
*/

#include <stdlib.h>
#include "list.h"
#include "header.h"

void	put_the_color(int res, int color, t_mlx ***tmp)
{
  t_mlx	**s;

  s = (*tmp);
  if (color == 100)
    {
      (*s)->data[res++] = 100;
      (*s)->data[res++] = 100;
      (*s)->data[res++] = 100;
      (*s)->data[res] = 100;
    }
  else if (color == 2)
    {
      (*s)->data[res++] = 0;
      (*s)->data[res++] = 255;
      (*s)->data[res++] = 255;
      (*s)->data[res] = 255;
    }
  else
    {
      (*s)->data[res++] = 0;
      (*s)->data[res++] = 80;
      (*s)->data[res++] = 80;
      (*s)->data[res] = 80;
    }
  (*tmp) = s;
}

void	draw_weapon(t_coord *co, int color, int size, t_mlx ***temp)
{
  t_mlx	**s;
  int	tmp;
  int	res;

  s = (*temp);
  co->c_xm = co->c_x + size;
  co->c_ym = co->c_y + size;
  while (co->c_y < co->c_ym)
    {
      tmp = co->c_x;
      while (tmp < co->c_xm)
	{
	  res = tmp * 4 + (co->c_y * 4 * WINX);
	  if (color == 1)
	    put_the_color(res, 100, &s);
	  else if (color == 2 || color == 3)
	    put_the_color(res, color, &s);
	  tmp++;
	}
      co->c_y++;
    }
  (*temp) = s;
}

void	weapon(t_mlx **s)
{
  int		i;
  int		j;
  t_coord	co;
  int		size;

  i = -1;
  size = (WINX_RAY / 3) / my_strlen((*s)->sword[0]);
  while ((*s)->sword[++i] != NULL)
    {
      j = 0;
      while ((*s)->sword[i][j])
	{
	  co.c_x = (WINX_RAY / 3) * 2 + j * size;
	  co.c_y = (WINY_RAY / 3) * 2 + i * size;
	  if ((*s)->sword[i][j] == '1')
	    draw_weapon(&co, 1, size, &s);
	  else if ((*s)->sword[i][j] == '2')
	    draw_weapon(&co, 2, size, &s);
	  else if ((*s)->sword[i][j] == '3')
	    draw_weapon(&co, 3, size, &s);
	  j++;
	}
    }
}
