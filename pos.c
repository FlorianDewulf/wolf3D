/*
** pos.c for wolf3d in /home/dewulf_f//afs/Igraph/Wolf/Dossier_propre/Propre
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Sun Jan 15 12:30:57 2012 florian dewulf
** Last update Sun Jan 15 19:48:15 2012 florian dewulf
*/

#include	"header.h"

void	put_square(t_coord *pos, t_mlx ***tmp)
{
  int	x;
  int	res;
  t_mlx	**s;

  s = (*tmp);
  while (pos->c_y < pos->c_ym)
    {
      x = pos->c_x;
      while (x < pos->c_xm)
	{
	  res = x * 4 + (WINX * 4 * pos->c_y);
	  (*s)->data[res++] = 0;
	  (*s)->data[res++] = 0;
	  (*s)->data[res++] = 255;
	  (*s)->data[res] = 0;
	  x++;
	}
      pos->c_y++;
    }
  (*tmp) = s;
}

void	pos_map(t_mlx **s)
{
  int		size;
  t_coord	posi;


  size = 200 / my_strlen((*s)->tab[0]);
  posi.c_x = ((*s)->perso->x0 - 0.5) * size + WINX_RAY - 1;
  posi.c_y = ((*s)->perso->y0 - 0.5) * size + WINY_RAY - 1;
  posi.c_xm = posi.c_x + size - 1;
  posi.c_ym = posi.c_y + size - 1;
  put_square(&posi, &s);
}
