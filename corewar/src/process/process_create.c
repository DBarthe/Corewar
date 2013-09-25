/*
** process_create.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Fri Mar  8 17:35:01 2013 barthelemy delemotte
** Last update Fri Mar 29 12:48:07 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"process.h"

t_process	*process_create(t_program *program)
{
  t_process	*process;

  if (program == NULL)
    return (NULL);
  if ((process = process_new()) == NULL)
    return (NULL);
  if (process_init(process, program) == RET_FAILURE)
    {
      free(process);
      return (NULL);
    }
  return (process);
}
