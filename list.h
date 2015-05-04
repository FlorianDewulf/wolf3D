/*
** list.h for list in /home/dewulf_f//afs/Igraph/Wolf
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Sun Jan  8 13:38:43 2012 florian dewulf
** Last update Sun Jan 15 17:13:13 2012 florian dewulf
*/

#ifndef		__LIST_H__
#define		__LIST_H__

typedef struct s_point
{
  float		x0;
  float		y0;
  float		angle;
}t_point;

typedef struct	s_coord
{
  int	c_x;
  int	c_xm;
  int	c_y;
  int	c_ym;
}t_coord;

typedef struct s_mlx
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img;
  char		*data;
  int		bpp;
  int		size;
  int		endian;
  t_point	*perso;
  char		**tab;
  char		**sword;
  int		speed;
}t_mlx;

#endif
