/*
** cpu_add_process.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/cpu
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Thu Mar 14 17:35:47 2013 barthelemy delemotte
** Last update Sun Mar 31 19:04:17 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"
#include	"cpu.h"
#include	"process.h"

int		cpu_add_process(t_cpu *cpu_p, t_process *process)
{
  static t_cpu	*cpu = NULL;

  if (cpu_p)
    cpu = cpu_p;
  else
    {
      if (cpu == NULL || cpu->processes == NULL)
	return (RET_FAILURE);
      if (my_list_enqueue(cpu->processes, process) == RET_FAILURE)
	return (RET_FAILURE);
      if (cpu->hook_process)
	cpu->hook_process(NULL, cpu->processes->length);
      return (RET_SUCCESS);
    }
  return (RET_SUCCESS);
}
