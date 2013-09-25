/*
** instruction_rw_storei.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/instruction/read_write
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Tue Mar 12 11:02:36 2013 barthelemy delemotte
** Last update Sat Mar 16 22:28:09 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"op.h"
#include	"instruction.h"
#include	"ram.h"

int		instruction_r_storei(t_instruction *instruction,
				     t_process *process, t_ram *ram)
{
  int		type_size[MAX_ARGS_NUMBER];

  if (instruction == NULL || process == NULL)
    return (RET_FAILURE);
  type_size[0] = REG_SIZE;
  type_size[1] = IND_SIZE;
  type_size[2] = IND_SIZE;
  type_size[3] = 0;
  instruction_read_args_mod(instruction, ram, process, type_size);
  return (RET_SUCCESS);
}

int		instruction_w_storei(t_instruction *instruction,
				     t_process *process, t_ram *ram)
{
  int		idx;

  idx = process->pc + (instruction->argv[1] + instruction->argv[2]) % IDX_MOD;
  idx %= MEM_SIZE;
  if (idx < 0)
    idx += MEM_SIZE;
  ram_set_int32(ram, idx, instruction->argv[0]);
  return (RET_SUCCESS);
}
