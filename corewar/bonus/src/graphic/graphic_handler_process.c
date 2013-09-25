/*
** graphic_handler_process.c for corewar in /home/raphy/Developement/tek1/corewar-2017-sauval_d/corewar/bonus/src/graphic
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Mar 31 13:42:07 2013 raphael defreitas
** Last update Sun Mar 31 13:48:49 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"graphic.h"

void			graphic_handler_process(t_graphic *pgraphic, int process)
{
  static t_graphic	*graphic = NULL;

  if (pgraphic)
    graphic = pgraphic;
  if (process > 0)
    graphic->process = process;
}

