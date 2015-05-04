/*
** main.c for main in /home/dewulf_f//afs/Igraph/fdf/Fil
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Sat Dec 10 14:50:44 2011 florian dewulf
** Last update Mon Jan 16 15:33:32 2012 Florian Dewulf
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../minilibx/mlx.h"
#include "header.h"
#include "get_next_line.h"

int	main(int ac, char **av)
{
  int	i;
  int	j;

  if (ac < 2)
    my_putstr("Le programme nécessite une map carrée et une arme\n");
  else if (ac < 3)
    my_putstr("Le programme nécessite une arme\n");
  else
    {
      i = open(av[1], O_RDONLY);
      j = open(av[2], O_RDONLY);
      if (i == -1 || j == -1)
	{
	  my_putstr("Fail fichier. Usage : ./wolf3d map arme\n");
	  return (1);
	}
      boucle(i, j);
      close(i);
      close(j);
    }
  return (0);
}
