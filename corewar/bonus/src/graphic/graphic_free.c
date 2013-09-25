/*
** graphic_free.c for corewar in /home/raphy/Developement/tmp/corewar/corewar/src/graphic
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Wed Mar 27 16:29:31 2013 raphael defreitas
** Last update Sun Mar 31 23:20:41 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	<SDL/SDL.h>
#include	"graphic.h"
#include	"op.h"

void		graphic_free(t_graphic *graphic)
{
  if (graphic != NULL)
    {
      if (graphic->screen)
	SDL_FreeSurface(graphic->screen);
      if (graphic->colors)
	free(graphic->colors);
      if (graphic->buf)
	free(graphic->buf);
      TTF_Quit();
      SDL_Quit();
      free(graphic);
    }
}
