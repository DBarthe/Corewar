/*
** brain_new.c for corewar in /home/raphy/Projects/prog_elem/corewar/corewar/src/brain
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jan 28 16:23:16 2013 raphael defreitas
** Last update Sat Mar 30 12:07:41 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"brain.h"

t_brain		*brain_new(void)
{
  t_brain	*brain;

  if ((brain = xmalloc(sizeof(t_brain))) == NULL)
    return (NULL);
  brain->game = NULL;
  brain->cpu = NULL;
  brain->ram = NULL;
  brain->programs = NULL;
  return (brain);
}
