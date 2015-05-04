/*
** my_strlen_modif.c for my_strlen modif in /home/dewulf_f//afs/Igraph/fdf
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Wed Dec  7 20:38:43 2011 florian dewulf
** Last update Sat Jan 14 13:42:29 2012 florian dewulf
*/

#include <unistd.h>
#include <stdlib.h>
#include "header.h"

void	*xmalloc(int size)
{
  void	*s;

  s = malloc(size);
  if (s == NULL)
    exit(EXIT_FAILURE);
  return (s);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
