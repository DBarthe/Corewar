/*
** cpu_free.c for corewar in /home/raphy/Projects/prog_elem/corewar/corewar/src/cpu
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jan 28 16:31:09 2013 raphael defreitas
** Last update Fri Mar  8 18:39:05 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"cpu.h"

void		cpu_free(t_cpu *cpu)
{
  if (cpu != NULL)
    {
      my_list_free(cpu->processes);
      free(cpu);
    }
}
