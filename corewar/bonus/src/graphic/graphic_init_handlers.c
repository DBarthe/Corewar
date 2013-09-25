/*
** graphic_init_handlers.c for corewar in /home/raphy/Developement/tek1/corewar-2017-sauval_d/corewar/bonus/src/graphic
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Mar 31 13:52:00 2013 raphael defreitas
** Last update Fri Apr  5 17:38:35 2013 raphael defreitas
*/

#include	"graphic.h"

void		graphic_init_handlers(t_graphic *graphic)
{
  graphic_handler_ram_set(graphic, -1, -1);
  graphic_handler_cycles(graphic, -1);
  graphic_handler_process(graphic, -1);
  graphic_handler_cycles_to_die(graphic, -1);
  graphic_handler_winner(graphic, -1, NULL);
  graphic_handler_update(graphic);
}
