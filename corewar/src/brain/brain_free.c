/*
** brain_free.c for corewar in /home/raphy/Projects/prog_elem/corewar/corewar/src/brain
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jan 28 16:27:16 2013 raphael defreitas
** Last update Sat Mar 16 21:23:36 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"brain.h"
#include	"game.h"
#include	"ram.h"
#include	"cpu.h"

void		brain_free(t_brain *brain)
{
  if (brain != NULL)
    {
      my_list_free(brain->programs);
      game_free(brain->game);
      cpu_free(brain->cpu);
      ram_free(brain->ram);
      free(brain);
    }
}
