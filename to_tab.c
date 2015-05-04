/*
** to_tab.c for wolf3d in /home/dewulf_f//afs/Igraph/Wolf/Dossier_propre/Propre
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Sat Jan 14 13:20:07 2012 florian dewulf
** Last update Sun Jan 15 12:54:01 2012 florian dewulf
*/

#include <stdlib.h>
#include "header.h"
#include "get_next_line.h"

char	**to_tab(int fd)
{
  char	**tab;
  char	*str;
  int	size;
  int	i;

  i = 1;
  str = get_next_line(fd);
  if (str == NULL)
    exit(my_putstr("Fail get next\n"));
  size = my_strlen(str);
  tab = xmalloc((size + 1) * sizeof(char *));
  tab[0] = str;
  while (i < size)
    {
      str = get_next_line(fd);
      if (str == NULL)
	exit(my_putstr("Fichier non carré\n"));
      tab[i] = str;
      i++;
    }
  tab[i] = NULL;
  return (tab);
}
