/*
** graphic_handler_cycles_to_die.c for corewar in /home/raphy/Developement/tmp/corewar/corewar/bonus
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Apr  5 17:35:57 2013 raphael defreitas
** Last update Fri Apr  5 17:41:46 2013 raphael defreitas
*/

#include	"graphic.h"

void			graphic_handler_cycles_to_die(t_graphic *graphicp, int cycles_to_die)
{
  static t_graphic	*graphic = NULL;

  if (graphicp && cycles_to_die == -1)
    graphic = graphicp;
  else
    graphic->cycles_to_die = cycles_to_die;
}
