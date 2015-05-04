/*
** sol_sky.c for sol_sky in /home/dewulf_f//afs/Igraph/Wolf
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Wed Jan  4 16:10:55 2012 florian dewulf
** Last update Sun Jan 15 19:13:19 2012 florian dewulf
*/

#include <stdlib.h>
#include "header.h"

void	skyyy(t_mlx **ml, int i)
{
  int	res;
  int	x;

  while (i < WINY_RAY)
    {
      x = 0;
      while (x < WINX_RAY)
	{
	  res = (x * 4) + ((i - 1) * 4 * WINX);
	  (*ml)->data[res++] = 30;
	  (*ml)->data[res++] = 30;
	  (*ml)->data[res++] = 30;
	  (*ml)->data[res] = 30;
	  x++;
	}
      i++;
    }
}

t_mlx	*put_sol_and_sky(t_mlx *ml)
{
  int	i;
  int	x;
  int	res;

  i = 0;
  while (i++ < (WINY_RAY / 2))
    {
      x = 0;
      while (x < WINX_RAY)
	{
	  res = (x * 4) + ((i - 1) * 4 * WINX);
	  ml->data[res++] = 0;
	  ml->data[res++] = 0;
	  ml->data[res++] = 0;
	  ml->data[res] = 0;
	  x++;
	}
    }
  skyyy(&ml, i);
  return (ml);
}
