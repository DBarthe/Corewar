/*
** graphic_handler_update.c for corewar in /home/raphy/Developement/tmp/corewar/corewar/bonus/src/graphic
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Apr  5 16:09:56 2013 raphael defreitas
** Last update Fri Apr  5 16:11:05 2013 raphael defreitas
*/

#include	"graphic.h"

void			graphic_handler_update(t_graphic *graphicp)
{
  static t_graphic	*graphic;

  if (graphicp)
    graphic = graphicp;
  else
    graphic_update(graphic);
}
