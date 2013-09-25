/*
** graphic_update.c for corewar in /home/raphy/Developement/tmp/cwr/corewar/src/graphic
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Mar 30 16:26:14 2013 raphael defreitas
** Last update Fri Apr  5 19:16:44 2013 raphael defreitas
*/

#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>
#include	"graphic.h"
#include	"program.h"

void			graphic_update(t_graphic *graphicp)
{
  static t_graphic	*graphic = NULL;

  if (graphicp)
    graphic = graphicp;
  if (graphic)
    {
      graphic_write_players(graphic);
      graphic_write_cycles(graphic);
      graphic_write_process(graphic);
      graphic_write_cycles_to_die(graphic);
      graphic_write_cycle_delta(graphic);
      SDL_Flip(graphic->screen);
    }
}
