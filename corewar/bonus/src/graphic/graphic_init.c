/*
** graphic_init.c for corewar in /home/raphy/Developement/tmp/corewar/corewar/src/graphic
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Wed Mar 27 16:33:13 2013 raphael defreitas
** Last update Sun Mar 31 04:16:47 2013 raphael defreitas
*/

#include	<limits.h>
#include	<stdlib.h>
#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>
#include	<time.h>
#include	"my.h"
#include	"graphic.h"
#include	"error.h"

static int	*init_colors()
{
  int		*colors;

  if ((colors = malloc(MAX_COLORS * sizeof(int))) == NULL)
    return (NULL);
  colors[0] = 0x000000 + 0x000000 + 0x0000ff;
  colors[1] = 0x000000 + 0x00ff00 + 0x000000;
  colors[2] = 0x000000 + 0x00ff00 + 0x0000ff;
  colors[3] = 0xff0000 + 0x000000 + 0x000000;
  colors[4] = 0xff0000 + 0x000000 + 0x0000ff;
  colors[5] = 0xff0000 + 0x00ff00 + 0x000000;
  colors[6] = colors[0] / 2;
  colors[7] = colors[1] / 2;
  colors[8] = colors[2] / 2;
  colors[9] = colors[3] / 2;
  colors[10] = colors[4] / 2;
  colors[11] = colors[5] / 2;
  return (colors);
}

int		graphic_init(t_graphic *graphic, t_list *programs)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (error_int(RET_FAILURE, ERR_SDL_INIT, SDL_GetError()));
  if (TTF_Init() == -1)
    return (error_int(RET_FAILURE, ERR_SDL_INIT, SDL_GetError()));
  graphic->screen = SDL_SetVideoMode(WIN_W, WIN_H, 16, SDL_HWSURFACE);
  if ((graphic->font = TTF_OpenFont("visitor1.ttf", 20)) == NULL)
    return (error_int(RET_FAILURE, ERR_SDL_INIT, "Cannot load font"));
  if (graphic->screen == NULL)
    return (error_int(RET_FAILURE, ERR_MALLOC));
  SDL_WM_SetCaption("Corewar - Barth, Damien, Marie & Raphy", NULL);
  if ((graphic->colors = init_colors()) == NULL)
    return (error_int(RET_FAILURE, ERR_MALLOC));
  graphic->prgms = programs;
  return (RET_SUCCESS);
}
