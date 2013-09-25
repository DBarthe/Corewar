/*
** process_execute.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/process
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sat Mar  9 06:58:25 2013 barthelemy delemotte
** Last update Fri Mar 29 12:48:31 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"process.h"
#include	"instruction.h"
#include	"ram.h"

static int	wait_0(t_process *process, t_game *game, t_ram *ram)
{
  t_instruction	*inst;

  if ((inst = instruction_get_next(ram, process->pc)) == NULL ||
      instruction_load(inst, process, ram) == RET_ERR_INST)
    {
      ram_hook_set(ram, (process->pc) % MEM_SIZE, 1);
      process->pc = (process->pc + 1) % MEM_SIZE;
    }
  return (RET_SUCCESS);
}

static int	wait_1(t_process *process, t_game *game, t_ram *ram)
{
  if (process->next_instruction != NULL)
    {
      instruction_write(process->next_instruction, process, ram);
      if (process->next_instruction->data[0] != 0x09)
	process->pc = (process->pc + process->next_instruction->data_len)
	  % MEM_SIZE;
      ram_hook_set(ram, (process->pc) % MEM_SIZE,
		   process->next_instruction->data_len);
      instruction_free(process->next_instruction);
    }
  else
    {
      process->pc = (process->pc + 1) % MEM_SIZE;
      ram_hook_set(ram, (process->pc) % MEM_SIZE, 1);
    }
  process->next_instruction = NULL;
  return (RET_SUCCESS);
}

int		process_execute(t_process *process, t_game *game, t_ram *ram)
{
  if (process == NULL || ram == NULL)
    return (RET_FAILURE);
  ram->last_user_no = process->pid;
  if (process->cycles_to_wait == 0)
    wait_0(process, game, ram);
  if (process->cycles_to_wait == 1)
    wait_1(process, game, ram);
  if (process->cycles_to_wait > 0)
    process->cycles_to_wait--;
  return (RET_SUCCESS);
}
