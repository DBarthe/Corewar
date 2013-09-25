/*
** process_new.c for corewar in /home/raphy/Projects/prog_elem/corewar/corewar/src/process
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jan 28 16:35:41 2013 raphael defreitas
** Last update Sun Mar 31 11:43:15 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"process.h"
#include	"my.h"

t_process	*process_new(void)
{
  t_process	*process;
  int		i;

  if ((process = xmalloc(sizeof(t_process))) == NULL)
    return (NULL);
  process->pid = PID_UNDEF;
  process->pc = 0;
  process->carry = CARRY_SUCCESS;
  process->cycles_to_wait = 0;
  i = 0;
  while (i < REG_NUMBER)
    {
      process->registres[i] = 0;
      i++;
    }
  return (process);
}
