/*
** cpu_disp_processes.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Fri Mar  8 18:11:02 2013 barthelemy delemotte
** Last update Sat Mar  9 09:03:09 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"cpu.h"
#include	"process.h"

int		cpu_disp_processes(t_cpu *cpu)
{
  t_list_item	*item;
  t_process	*process;

  if (cpu == NULL || cpu->processes == NULL)
    return (RET_FAILURE);
  item = cpu->processes->top;
  while (item)
    {
      process = item->data;
      if (process != NULL)
	{
	  process_disp(process);
	}
      item= item->next;
    }
  return (RET_SUCCESS);
}
