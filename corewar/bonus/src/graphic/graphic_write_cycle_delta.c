/*
** graphic_write_process.c for corewar in /home/raphy/Developement/tek1/corewar-2017-sauval_d/corewar/bonus/src/graphic
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Mar 31 03:31:14 2013 raphael defreitas
** Last update Fri Apr  5 19:19:57 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>
#include	"graphic.h"
#include	"op.h"

static void	write_outlined(t_graphic *graphic, char *txt, SDL_Rect pos)
{
  SDL_Color	clr;
  SDL_Color	bg;

  clr.r = 0;
  clr.g = 0;
  clr.b = 0;
  bg.r = 60;
  bg.g = 60;
  bg.b = 60;
  TTF_SetFontOutline(graphic->font, 1);
  if ((graphic->tmp = TTF_RenderText_Shaded(graphic->font, txt, clr, bg)))
    {
      SDL_BlitSurface(graphic->tmp, NULL, graphic->screen, &pos);
      SDL_FreeSurface(graphic->tmp);
    }
}

static void	write_colored(t_graphic *graphic, char *txt, SDL_Rect pos)
{
  SDL_Color	clr;
  SDL_Color	bg;

  clr.r = 0xff;
  clr.g = 0xff;
  clr.b = 0xff;
  bg.r = 60;
  bg.g = 60;
  bg.b = 60;
  TTF_SetFontOutline(graphic->font, 0);
  if ((graphic->tmp = TTF_RenderText_Shaded(graphic->font, txt, clr, bg)))
    {
      SDL_BlitSurface(graphic->tmp, NULL, graphic->screen, &pos);
      SDL_FreeSurface(graphic->tmp);
    }
}

static void	fill_text(char **str, int nbr)
{
  int		divi;
  int		i;

  my_strcpy(*str, "Cycle delta: ");
  i = strlen(*str);
  if (nbr < 0)
    {
      (*str)[i++] = '-';
      nbr = -nbr;
    }
  divi = 1;
  while ((nbr / divi) >= 10)
    divi *= 10;
  while (divi)
    {
      (*str)[i] = (nbr / divi) % 10 + '0';
      divi /= 10;
      i++;
    }
  (*str)[i] = '\0';
}

void		graphic_write_cycle_delta(t_graphic *graphic)
{
  SDL_Rect	pos;

  pos.x = WIN_W - 300;
  pos.y = 49;
  fill_text(&graphic->buf, CYCLE_DELTA);
  write_outlined(graphic, graphic->buf, pos);
  write_colored(graphic, graphic->buf, pos);
}
