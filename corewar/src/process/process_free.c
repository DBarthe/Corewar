/*
** process_free.c for corewar in /home/raphy/Projects/prog_elem/corewar/corewar/src/process
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jan 28 16:37:31 2013 raphael defreitas
** Last update Sat Mar 30 13:15:57 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"process.h"

void		process_free(t_process *process)
{
  if (process != NULL)
    free(process);
}
