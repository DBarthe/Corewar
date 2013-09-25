/*
** cpu_create_processes.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/cpu
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Fri Mar  8 17:43:42 2013 barthelemy delemotte
** Last update Sat Mar  9 09:02:53 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"cpu.h"
#include	"program.h"
#include	"process.h"

int		cpu_create_processes(t_cpu *cpu, t_list *programs)
{
  t_list_item	*prog_item;
  t_program	*program;
  t_process	*process;

  if (cpu == NULL || programs == NULL)
    return (RET_FAILURE);
  prog_item = programs->top;
  while (prog_item)
    {
      program = prog_item->data;
      if (program != NULL)
	{
	  process = process_create(program);
	  my_list_enqueue(cpu->processes, process);
	}
      prog_item = prog_item->next;
    }
  return (RET_SUCCESS);
}
