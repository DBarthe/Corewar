/*
** graphic_splash_winner.c for corewar in /home/raphy/Developement/tek1/corewar-2017-sauval_d/corewar/bonus/src/graphic
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Mar 31 13:50:20 2013 raphael defreitas
** Last update Sun Mar 31 23:10:29 2013 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"graphic.h"

static void	fill_screen(t_graphic *graphic)
{
  SDL_Rect	pos;
  Uint32	rgb;

  pos.x = 0;
  pos.y = 0;
  while (pos.y < WIN_H)
    {
      if ((graphic->tmp = SDL_CreateRGBSurface(SDL_HWSURFACE, WIN_W, SQR_H, 32,
					       0, 0, 0, 0)))
	{
	  rgb = SDL_MapRGB(graphic->tmp->format, 0, 0, 0);
	  SDL_FillRect(graphic->tmp, NULL, rgb);
	  SDL_BlitSurface(graphic->tmp, NULL, graphic->screen, &pos);
	  SDL_FreeSurface(graphic->tmp);
	  SDL_Flip(graphic->screen);
	}
      pos.y += SQR_H;
    }
}

static void		write_winner(t_graphic *graphic, int num,
				     const char *name)
{
  SDL_Color		clr;
  SDL_Rect		pos;

  clr.r = ((char *)&graphic->colors[num % MAX_COLORS])[0];
  clr.g = ((char *)&graphic->colors[num % MAX_COLORS])[1];
  clr.b = ((char *)&graphic->colors[num % MAX_COLORS])[2];
  if ((graphic->tmp =
       TTF_RenderText_Blended(graphic->font, name, clr)))
    {
      pos.x = (WIN_W / 2) - (graphic->tmp->w / 2);
      pos.y = (WIN_H / 2) - (graphic->tmp->h / 2);
      SDL_BlitSurface(graphic->tmp, NULL, graphic->screen, &pos);
      SDL_FreeSurface(graphic->tmp);
      SDL_Flip(graphic->screen);
    }
}

static void		write_misc(t_graphic *graphic, int num)
{
  SDL_Color		clr;
  SDL_Rect		pos;

  my_strcpy(graphic->buf, "The winner is");
  clr.r = ((char *)&graphic->colors[num % MAX_COLORS])[0];
  clr.g = ((char *)&graphic->colors[num % MAX_COLORS])[1];
  clr.b = ((char *)&graphic->colors[num % MAX_COLORS])[2];
  if ((graphic->tmp =
       TTF_RenderText_Blended(graphic->font, graphic->buf, clr)))
    {
      pos.x = (WIN_W / 2) - (graphic->tmp->w / 2);
      pos.y = (WIN_H / 2) - (graphic->tmp->h / 2) - 30;
      SDL_BlitSurface(graphic->tmp, NULL, graphic->screen, &pos);
      SDL_FreeSurface(graphic->tmp);
      SDL_Flip(graphic->screen);
    }
}

void			graphic_handler_winner(t_graphic *pgraphic,
						 int num, const char *name)
{
  static t_graphic	*graphic = NULL;

  if (pgraphic)
    graphic = pgraphic;
  if (num >= 0 && name)
    {
      fill_screen(graphic);
      write_winner(graphic, num, name);
      write_misc(graphic, num);
    }
}
