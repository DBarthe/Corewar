/*
** graphic_write_players.c for corewar in /home/raphy/Developement/tek1/corewar-2017-sauval_d/corewar/bonus/src/graphic
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Mar 31 03:01:06 2013 raphael defreitas
** Last update Sun Mar 31 04:52:50 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>
#include	"my.h"
#include	"graphic.h"
#include	"program.h"

static void	write_outlined(t_graphic *graphic, t_program *prgm, int i,
			       SDL_Rect pos)
{
  SDL_Color	clr;

  clr.r = 0;
  clr.g = 0;
  clr.b = 0;
  TTF_SetFontOutline(graphic->font, 1);
  if ((graphic->tmp =
       TTF_RenderText_Blended(graphic->font, prgm->name, clr)))
    {
      SDL_BlitSurface(graphic->tmp, NULL, graphic->screen, &pos);
      SDL_FreeSurface(graphic->tmp);
    }
}

static void	write_colored(t_graphic *graphic, t_program *prgm, int i,
			      SDL_Rect pos)
{
  SDL_Color	clr;

  clr.r = ((char *)&graphic->colors[prgm->player_id % MAX_COLORS])[0];
  clr.g = ((char *)&graphic->colors[prgm->player_id % MAX_COLORS])[1];
  clr.b = ((char *)&graphic->colors[prgm->player_id % MAX_COLORS])[2];
  TTF_SetFontOutline(graphic->font, 0);
  if ((graphic->tmp =
       TTF_RenderText_Blended(graphic->font, prgm->name, clr)))
    {
      SDL_BlitSurface(graphic->tmp, NULL, graphic->screen, &pos);
      SDL_FreeSurface(graphic->tmp);
    }
}

void		graphic_write_players(t_graphic *graphic)
{
  t_list_item	*item;
  t_program	*prgm;
  int		i;
  SDL_Rect	pos;

  pos.x = 5;
  pos.y = 5;
  i = 0;
  item = graphic->prgms->top;
  while (item)
    {
      prgm = item->data;
      write_outlined(graphic, prgm, i, pos);
      write_colored(graphic, prgm, i, pos);
      pos.y += 23;
      i++;
      item = item->next;
    }
}
