/*
** instruction_rw_load.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/instruction/read_write
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Tue Mar 12 12:17:45 2013 barthelemy delemotte
** Last update Thu Mar 14 14:12:31 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"op.h"
#include	"instruction.h"
#include	"process.h"

int		instruction_r_load(t_instruction *instruction,
				   t_process *process, t_ram *ram)
{
  int		len;
  int		type_size[MAX_ARGS_NUMBER];

  if (instruction == NULL || process == NULL)
    return (RET_FAILURE);
  type_size[0] = REG_SIZE;
  type_size[1] = 0;
  if (instruction->data[0] == 0x0d)
    len = instruction_read_args(instruction, ram, process, type_size);
  else
    len = instruction_read_args_mod(instruction, ram, process, type_size);
  instruction->argv[1] = instruction_get_val_dir(instruction->data + len, 1);
  return (RET_SUCCESS);
}

int		instruction_w_load(t_instruction *instruction,
				   t_process *process, t_ram *ram)
{
  (void)ram;
  if (instruction && process)
    process_set_registre(process, instruction->argv[1], instruction->argv[0]);
  process->carry = (instruction->argv[0] == 0 ? 1 : 0);
  return (RET_SUCCESS);
}
