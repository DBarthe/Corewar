/*
** graphic_new.c for corewar in /home/raphy/Developement/tmp/corewar/corewar/src/graphic
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Wed Mar 27 16:29:35 2013 raphael defreitas
** Last update Sun Mar 31 19:23:44 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"
#include	"graphic.h"

t_graphic	*graphic_new()
{
  t_graphic	*graphic;

  if ((graphic = malloc(sizeof(t_graphic))) == NULL)
    return (NULL);
  if ((graphic->buf = malloc(1024 * sizeof(char))) == NULL)
    return (NULL);
  graphic->screen = NULL;
  graphic->font = NULL;
  graphic->tmp = NULL;
  return (graphic);
}
