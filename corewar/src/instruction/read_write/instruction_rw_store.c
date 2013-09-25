/*
** instruction_rw_store.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/instruction/read_write
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Mar 11 18:29:58 2013 barthelemy delemotte
** Last update Tue Mar 19 23:29:22 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"op.h"
#include	"instruction.h"
#include	"ram.h"
#include	"process.h"

int		instruction_r_store(t_instruction *instruction,
				    t_process *process, t_ram *ram)
{
  int		arg1;
  int		arg2;
  int		type2;

  (void)ram;
  if (instruction == NULL || process == NULL)
    return (RET_FAILURE);
  arg1 = instruction_get_val_reg(instruction->data + 2, REG_SIZE, process);
  type2 = instruction_get_arg_type(instruction->data + 1, 2);
  if (type2 == T_IND)
    arg2 = instruction_get_val_dir(instruction->data + 3, IND_SIZE);
  else if (type2 == T_REG)
    arg2 = instruction_get_val_dir(instruction->data + 3, 1);
  else
    return (RET_FAILURE);
  instruction->argv[0] = arg1;
  instruction->argv[1] = arg2;
  return (RET_SUCCESS);
}

int		instruction_w_store(t_instruction *instruction,
				    t_process *process, t_ram *ram)
{
  char		type;
  int		idx;

  type = instruction_get_arg_type(instruction->data + 1, 2);
  if (type == T_IND)
    {
      idx = process->pc + (instruction->argv[1]) % IDX_MOD;
      idx %= MEM_SIZE;
      if (idx < 0)
	idx += MEM_SIZE;
      ram_set_int32(ram, idx, instruction->argv[0]);
    }
  else if (type == T_REG)
    {
      process_set_registre(process, instruction->argv[1],
			   instruction->argv[0]);
    }
  return (RET_SUCCESS);
}
