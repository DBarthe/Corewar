/*
** instruction_rw_zjump.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/instruction/read_write
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Mar 11 18:48:30 2013 barthelemy delemotte
** Last update Tue Mar 19 23:55:48 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"op.h"
#include	"instruction.h"

int		instruction_r_zjump(t_instruction *instruction,
				    t_process *process, t_ram *ram)
{
  int		arg1;

  (void)ram;
  if (instruction == NULL || process == NULL)
    return (RET_FAILURE);
  arg1 = instruction_get_val_dir(instruction->data + 1, IND_SIZE);
  instruction->argv[0] = arg1;
  return (RET_SUCCESS);
}

int		instruction_w_zjump(t_instruction *instruction,
				    t_process *process, t_ram *ram)
{
  (void)ram;
  if (instruction == NULL || process == NULL)
    return (RET_FAILURE);
  if (process->carry)
    {
      process->pc += (instruction->argv[0] % IDX_MOD);
      process->pc %= MEM_SIZE;
      if (process->pc < 0)
	process->pc = MEM_SIZE + process->pc;
    }
  else
    process->pc = (process->pc + 3) % MEM_SIZE;
  return (RET_SUCCESS);
}
