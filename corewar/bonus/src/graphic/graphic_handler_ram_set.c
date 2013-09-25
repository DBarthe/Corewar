/*
** graphic_handler_ram_set.c for corewar in /home/raphy/Developement/tmp/corewar/corewar/src/graphic
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Mar 28 11:35:37 2013 raphael defreitas
** Last update Fri Apr  5 16:08:10 2013 raphael defreitas
*/

#include		<stdio.h>
#include		<SDL/SDL.h>
#include		"my.h"
#include		"graphic.h"

void			graphic_handler_ram_set(t_graphic *pgraphic,
						int player, int mem)
{
  static t_graphic	*graphic = NULL;
  unsigned char		*clr;
  SDL_Rect		pos;
  Uint32		rgb;

  if (pgraphic)
    graphic = pgraphic;
  if (graphic && player >= 0 && mem >= 0)
    {
      clr = (unsigned char *)(&(graphic->colors[player % MAX_COLORS]));
      if ((graphic->tmp = SDL_CreateRGBSurface(SDL_HWSURFACE, SQR_W, SQR_H, 32,
					       0, 0, 0, 0)))
	{
	  rgb = SDL_MapRGB(graphic->tmp->format, clr[0], clr[1], clr[2]);
	  SDL_FillRect(graphic->tmp, NULL, rgb);
	  pos.x = 1 + (mem * (SQR_W + 1)) % (WIN_W + SQR_W);
	  pos.x = (pos.x / SQR_W == 0) ? 1 : pos.x;
	  pos.y = 1 + ((mem * (SQR_W + 1)) / (WIN_W + SQR_W)) * (SQR_H + 1);
	  SDL_BlitSurface(graphic->tmp, NULL, graphic->screen, &pos);
	  SDL_FreeSurface(graphic->tmp);
	}
    }
}
