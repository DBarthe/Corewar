/*
** cpu_execution.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Fri Mar  8 20:43:22 2013 barthelemy delemotte
** Last update Sat Mar 16 22:44:13 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"cpu.h"
#include	"process.h"

int		cpu_execution(t_cpu *cpu, t_game *game, t_ram *ram)
{
  t_list_item	*item;
  t_process	*process;

  if (cpu == NULL || game == NULL)
    return (RET_FAILURE);
  item = cpu->processes->top;
  while (item)
    {
      process = item->data;
      if (process != NULL)
	{
	  if (process_execute(process, game, ram) == RET_FAILURE)
	    return (RET_FAILURE);
	}
      item = item->next;
    }
  return (RET_SUCCESS);
}
