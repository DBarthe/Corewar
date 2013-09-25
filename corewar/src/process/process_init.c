/*
** process_init.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Fri Mar  8 17:29:46 2013 barthelemy delemotte
** Last update Fri Mar  8 17:34:45 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"process.h"
#include	"program.h"

int		process_init(t_process *process, t_program *program)
{
  if (program == NULL)
    return (RET_FAILURE);
  process->pid = program->player_id;
  process->registres[0] = program->player_id;
  process->pc = program->load_addr;
  return (RET_SUCCESS);
}
