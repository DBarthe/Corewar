/*
** cpu_kill_process.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/cpu
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Thu Mar 14 17:43:59 2013 barthelemy delemotte
** Last update Sun Mar 31 19:02:16 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"
#include	"cpu.h"
#include	"process.h"

int		cpu_kill_process(t_cpu *cpu, int pid)
{
  t_list_item	*item;
  t_list_item	*to_delete;
  t_process	*process;
  int		ret;

  if (cpu == NULL || cpu->processes == NULL)
    return (RET_ERROR);
  item = cpu->processes->top;
  ret = 0;
  while (item)
    {
      process = item->data;
      if (process && process->pid == pid)
	{
	  to_delete = item;
	  item = item->next;
	  my_list_delete(cpu->processes, to_delete);
	  ret++;
	}
      else
	item = item->next;
    }
  if (cpu->hook_process)
    cpu->hook_process(NULL, cpu->processes->length);
  return (ret);
}
