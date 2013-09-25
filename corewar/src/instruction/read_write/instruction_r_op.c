/*
** instruction_r_op.c for corewar - rw in /home/delemo_b/epitech_1/corewar/corewar/src/instruction/read_write
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Mar 11 18:57:19 2013 barthelemy delemotte
** Last update Sun Mar 31 11:22:22 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"op.h"
#include	"instruction.h"

int		instruction_r_op(t_instruction *instruction,
				 t_process *process, t_ram *ram)
{
  int		arg1;
  int		arg2;
  int		arg3;

  (void)ram;
  if (instruction == NULL || process == NULL)
    return (RET_FAILURE);
  arg1 = instruction_get_val_reg(instruction->data + 2, REG_SIZE, process);
  arg2 = instruction_get_val_reg(instruction->data + 3, REG_SIZE, process);
  arg3 = instruction_get_val_dir(instruction->data + 4, 1);
  instruction->argv[0] = arg1;
  instruction->argv[1] = arg2;
  instruction->argv[2] = arg3;
  return (RET_SUCCESS);
}

static int	to_size(char t)
{
  if (t == POC_DIR)
    return (DIR_SIZE);
  else if (t == POC_IND)
    return (IND_SIZE);
  else if (t == POC_REG)
    return (1);
  return (0);
}

static int	get_arg(t_instruction *instruction, t_process *process,
			t_ram *ram, char t1)
{
  int		len;
  int		arg2;
  char		t2;

  t2 = instruction_get_arg_type(instruction->data + 1, 2);
  len = to_size(t1) + 2;
  if (t2 == POC_DIR)
    arg2 = instruction_get_val_dir(instruction->data + len,  DIR_SIZE);
  else if (t2 == POC_IND)
    arg2 = instruction_get_val_ind_mod(instruction->data + len, DIR_SIZE,
				       ram, process->pc);
  else if (t2 == POC_REG)
    arg2 = instruction_get_val_reg(instruction->data + len, REG_SIZE, process);
  return (arg2);
}

int		instruction_r_op_b(t_instruction *instruction,
				 t_process *process, t_ram *ram)
{
  int		arg1;
  int		arg2;
  int		arg3;
  int		t1;

  if (instruction == NULL || process == NULL)
    return (RET_FAILURE);
  t1 = instruction_get_arg_type(instruction->data + 1, 1);
  if (t1 == POC_DIR)
    arg1 = instruction_get_val_dir(instruction->data + 2, DIR_SIZE);
  else if (t1 == POC_IND)
    arg1 = instruction_get_val_ind_mod(instruction->data + 2, DIR_SIZE,
				       ram, process->pc);
  else if (t1 == POC_REG)
    arg1 = instruction_get_val_reg(instruction->data + 2, REG_SIZE, process);
  arg2 = get_arg(instruction, process, ram, t1);
  arg3 = instruction_get_val_dir(instruction->data + 4, 1);
  instruction->argv[0] = arg1;
  instruction->argv[1] = arg2;
  instruction->argv[2] = arg3;
  return (RET_SUCCESS);
}

