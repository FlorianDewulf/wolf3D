/*
** func_bis.c for func in /home/dewulf_f//afs/Igraph/Wolf
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Sun Jan  8 14:44:30 2012 florian dewulf
** Last update Sat Jan 14 21:29:44 2012 florian dewulf
*/

#include <stdlib.h>
#include "header.h"

void	put_color(t_mlx **p, int color, int i)
{
  if (color == 0)
    {
      (*p)->data[i] = 255;
      (*p)->data[i + 1] = 255;
      (*p)->data[i + 2] = 255;
      (*p)->data[i + 3] = 255;
    }
  else if (color == 1)
    {
      (*p)->data[i] = 0;
      (*p)->data[i + 1] = 0;
      (*p)->data[i + 2] = 0;
      (*p)->data[i + 3] = 0;
    }
  else
    {
      (*p)->data[i] = 255;
      (*p)->data[i + 1] = 0;
      (*p)->data[i + 2] = 0;
      (*p)->data[i + 3] = 0;
    }
}
