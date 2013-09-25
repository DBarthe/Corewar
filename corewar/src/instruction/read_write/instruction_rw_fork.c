/*
** instruction_rw_fork.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/instruction/read_write
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Tue Mar 12 11:14:21 2013 barthelemy delemotte
** Last update Sat Mar 30 16:16:57 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"op.h"
#include	"instruction.h"
#include	"process.h"
#include	"cpu.h"
#include	"error.h"

int		instruction_r_fork(t_instruction *instruction,
				   t_process *process, t_ram *ram)
{
  if (instruction == NULL || process == NULL)
    return (RET_FAILURE);
  instruction->argv[0] = instruction_get_val_dir(instruction->data + 1,
						 IND_SIZE);
  return (RET_SUCCESS);
}

int		instruction_w_fork(t_instruction *instruction,
				   t_process *process, t_ram *ram)
{
  t_process	*child;

  if ((child = process_dup(process, process->pid)) == NULL)
    return (error_int(RET_FAILURE, ERR_MALLOC));
  if (instruction->data[0] == 0x0c)
    child->pc = process->pc + (instruction->argv[0] % IDX_MOD) - 1;
  else
    child->pc = process->pc + instruction->argv[0] - 1;
  child->pc %= MEM_SIZE;
  if (child->pc < 0)
    child->pc = MEM_SIZE + child->pc;
  cpu_add_process(NULL, child);
  return (RET_SUCCESS);
}
