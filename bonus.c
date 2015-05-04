/*
** bonus.c for wolf in /home/dewulf_f//afs/Igraph/Wolf/Dossier_propre/Propre
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Sat Jan 14 16:34:24 2012 florian dewulf
** Last update Sun Jan 15 19:02:32 2012 florian dewulf
*/

#include <stdlib.h>
#include "header.h"

void	cadre(t_mlx **stru)
{
  int	x;
  int	y1;
  int	res;

  y1 = 0;
  while (y1 <= WINY_RAY)
    {
      res = WINX_RAY * 4 + y1 * 4 * WINX;
      (*stru)->data[res++] = 255;
      (*stru)->data[res++] = 255;
      (*stru)->data[res++] = 255;
      (*stru)->data[res++] = 255;      
      y1++;
    }
  y1 = WINY_RAY;
  x = 0;
  while (x < WINX_RAY)
    {
      res = x * 4 + WINY_RAY * 4 * WINX;
      (*stru)->data[res++] = 255;
      (*stru)->data[res++] = 255;
      (*stru)->data[res++] = 255;
      (*stru)->data[res++] = 255;
      x++;
    }
}

void	draw_square(int x, int y, t_mlx ***tmp, int size)
{
  int	res;
  int	temp;
  int	xmax;
  int	ymax;
  t_mlx	**stru;
  int	col;

  stru = (*tmp);
  ((*stru)->tab[y][x] == '1') ? (col = 0) : (col = 255);
  x = x * size + WINX_RAY - 1;
  y = y * size + WINY_RAY - 2;
  (temp = x) ? (ymax = y + size) : (ymax = y + size);
  xmax = x + size;
  while (++y < ymax)
    {
      x = temp;
      while (x < xmax - 1)
	{
	  res = (x * 4) + (y * WINX * 4);
	  (*stru)->data[res++] = col;
	  (*stru)->data[res++] = col;
	  (*stru)->data[res++] = col;
	  ((*stru)->data[res] = col) ? x++ : x++;
	}
    }
}

void	map(t_mlx **stru)
{
  int	size;
  int	i;
  int	j;

  i = 0;
  size = 200 / my_strlen((*stru)->tab[0]);
  while ((*stru)->tab[i] != NULL)
    {
      j = 0;
      while ((*stru)->tab[i][j])
	{
	  draw_square(j, i, &stru, size);
	  j++;
	}
      i++;
    }
}

void	viseur(t_mlx **stru)
{
  int	pt_a;
  int	pt_b;
  int	res;

  pt_a = WINX / 2 - 12;
  pt_b = pt_a + 22;
  while (++pt_a < pt_b)
    {
      res = pt_a * 4 + ((WINY_RAY/ 2) * 4 * WINX);
      (*stru)->data[res++] = 255;
      (*stru)->data[res++] = 255;
      (*stru)->data[res++] = 255;
      (*stru)->data[res++] = 255;
    }
  pt_a = WINY_RAY / 2 - 11;
  pt_b = pt_a + 21;
  while (pt_a < pt_b)
    {
      res = (WINX / 2) * 4 + (pt_a * 4 * WINX);
      (*stru)->data[res++] = 255;
      (*stru)->data[res++] = 255;
      (*stru)->data[res++] = 255;
      (*stru)->data[res++] = 255;
      pt_a++;
    }
}
