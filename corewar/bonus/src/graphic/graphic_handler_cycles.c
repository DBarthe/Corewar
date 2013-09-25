/*
** graphic_handler_cycles_left.c for corewar in /home/raphy/Developement/tek1/corewar-2017-sauval_d/corewar/bonus/src/graphic
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Mar 31 13:42:07 2013 raphael defreitas
** Last update Sun Mar 31 18:56:21 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"graphic.h"

void			graphic_handler_cycles(t_graphic *pgraphic, int cycles)
{
  static t_graphic	*graphic = NULL;

  if (pgraphic)
    graphic = pgraphic;
  if (cycles > 0)
    graphic->cycles = cycles;
}

