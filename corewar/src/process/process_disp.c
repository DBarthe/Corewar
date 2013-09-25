/*
** process_disp.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Fri Mar  8 18:01:37 2013 barthelemy delemotte
** Last update Fri Mar  8 18:30:48 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"process.h"

int		process_disp(t_process *process)
{
  if (process == NULL)
    return (RET_FAILURE);
  my_printf("process pid=%d, pc=%d, reg[0]=%d, carry=%d\n",
	    process->pid, process->pc, process->registres[0],
	    (int)process->carry);
  return (RET_SUCCESS);
}
