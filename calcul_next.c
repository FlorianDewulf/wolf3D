/*
** calcul_next.c for wolf3d in /home/dewulf_f//afs/Igraph/Wolf/Dossier_propre/Propre
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Sun Jan 15 13:35:34 2012 florian dewulf
** Last update Sun Jan 15 15:28:20 2012 florian dewulf
*/

#include	"header.h"

void	put_the_limit(t_mlx ***tmp, int y1, int i)
{
  t_mlx	**s;
  int	r;

  s = (*tmp);
  r = (i * 4) + (y1 * WINX * 4);
  (*s)->data[r] = 250;
  (*s)->data[r + 1] = 250;
  (*s)->data[r + 2] = 100;
  (*s)->data[r + 3] = 0;
  (*tmp) = s;
}

void	put_the_tron(t_mlx ***tmp, int i, int y1, int color)
{
  int	r;
  t_mlx	**s;

  s = (*tmp);
  r = (i * 4) + (y1 * WINX * 4);
  if (color == 1)
    {
      (*s)->data[r++] = 15;
      (*s)->data[r++] = 15;
      (*s)->data[r++] = 5;
      (*s)->data[r] = 5;
    }
  else
    {
      (*s)->data[r++] = 45;
      (*s)->data[r++] = 45;
      (*s)->data[r++] = 35;
      (*s)->data[r] = 35;
    }
  (*tmp) = s;
}
