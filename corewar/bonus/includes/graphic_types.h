/*
** graphic_types.h for corewar in /home/raphy/Developement/tmp/corewar/corewar/includes
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Wed Mar 27 16:27:41 2013 raphael defreitas
** Last update Fri Apr  5 17:40:44 2013 raphael defreitas
*/

#ifndef		GRAPHIC_TYPES_H_
# define	GRAPHIC_TYPES_H_

#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>
#include	"my.h"
#include	"op.h"

typedef struct
{
  SDL_Surface	*screen;
  TTF_Font	*font;
  SDL_Surface	*tmp;
  t_list	*prgms;
  int		*colors;
  int		cycles;
  int		cycles_to_die;
  int		process;
  char		*buf;
}		t_graphic;

#endif /* !GRAPHIC_TYPES_H_ */
