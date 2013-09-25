/*
** instruction_read_args.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/instruction/read_write
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Mar 11 20:22:58 2013 barthelemy delemotte
** Last update Fri Mar 29 12:46:12 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"op.h"
#include	"instruction.h"

static int	to_size(char t, int size)
{
  if (t == T_DIR)
    return (size);
  else if (t == T_IND)
    return (IND_SIZE);
  else if (t == T_REG)
    return (1);
  return (0);
}

int		instruction_read_args_mod(t_instruction *instruction,
					  t_ram *ram, t_process *process,
					  int type_size[MAX_ARGS_NUMBER])
{
  int		i;
  int		arg;
  int		type;
  int		len;

  i = 0;
  len = 2;
  while (type_size[i] > 0)
    {
      type = instruction_get_arg_type(instruction->data + 1, i + 1);
      if (type == T_DIR)
	arg = instruction_get_val_dir(instruction->data + len, type_size[i]);
      else if (type == T_IND)
	arg = instruction_get_val_ind_mod(instruction->data + len,
					  type_size[i], ram, process->pc);
      else if (type == T_REG)
	arg = instruction_get_val_reg(instruction->data + len, type_size[i],
				      process);
      instruction->argv[i] = arg;
      len += to_size(type, type_size[i]);
      i++;
    }
  return (len);
}

int		instruction_read_args(t_instruction *instruction, t_ram *ram,
				      t_process *process,
				      int type_size[MAX_ARGS_NUMBER])
{
  int		i;
  int		arg;
  int		type;
  int		len;

  i = 0;
  len = 2;
  while (type_size[i] > 0)
    {
      type = instruction_get_arg_type(instruction->data + 1, i + 1);
      if (type == T_DIR)
	arg = instruction_get_val_dir(instruction->data + len, type_size[i]);
      else if (type == T_IND)
	arg = instruction_get_val_ind(instruction->data + len,
				      type_size[i], ram, process->pc);
      else if (type == T_REG)
	arg = instruction_get_val_reg(instruction->data + len, type_size[i],
				      process);
      instruction->argv[i] = arg;
      len += to_size(type, type_size[i]);
      i++;
    }
  return (RET_SUCCESS);
}
