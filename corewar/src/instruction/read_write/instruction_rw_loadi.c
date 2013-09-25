/*
** instruction_rw_loadi.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/instruction/read_write
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Mar 11 17:30:31 2013 barthelemy delemotte
** Last update Thu Mar 14 14:28:06 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"op.h"
#include	"instruction.h"
#include	"ram.h"
#include	"process.h"

static int	get_val_at_sum(t_instruction *instruction,
				    t_process *process, t_ram *ram)
{
  int		sum;
  char		buffer[REG_SIZE];
  int		i;

  if (instruction->data[0] == 0x0a)
    sum = (instruction->argv[0] % IDX_MOD) + instruction->argv[1];
  else
    sum = instruction->argv[0] + instruction->argv[1];
  ram_get_n_in_buffer(ram, sum, buffer, REG_SIZE);
  i = 0;
  instruction->argv[3] = 0;
  while (i < REG_SIZE)
    {
      instruction->argv[3] <<= 8;
      instruction->argv[3] += buffer[i];
      i++;
    }
  return (RET_SUCCESS);
}

int		instruction_r_loadi(t_instruction *instruction,
				    t_process *process, t_ram *ram)
{
  int		len;
  int		type_size[MAX_ARGS_NUMBER];

  if (instruction == NULL || process == NULL)
    return (RET_FAILURE);
  type_size[0] = IND_SIZE;
  type_size[1] = IND_SIZE;
  type_size[2] = 0;
  if (instruction->data[0] == 0x0e)
    len = instruction_read_args(instruction, ram, process, type_size);
  else
    len = instruction_read_args_mod(instruction, ram, process, type_size);
  instruction->argv[2] = instruction_get_val_dir(instruction->data + len, 1);
  get_val_at_sum(instruction, process, ram);
  return (RET_SUCCESS);
}

int		instruction_w_loadi(t_instruction *instruction,
				    t_process *process, t_ram *ram)
{
  process_set_registre(process, instruction->argv[2], instruction->argv[3]);
  process->carry = (instruction->argv[3] == 0 ? 1 : 0);
  return (RET_SUCCESS);
}
