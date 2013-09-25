/*
** instruction_read.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/instruction/read_write
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Tue Mar 12 12:00:21 2013 barthelemy delemotte
** Last update Sat Mar 30 12:55:53 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"instruction.h"

/*
** Please, let us use global !
*/
static int	if_tree_2(t_instruction *instruction,
			  t_process *process, t_ram *ram, int i)
{
  char		op;

  op = instruction->data[0];
  if (op == i++)
    instruction_r_zjump(instruction, process, ram);
  else if (op == i++)
    instruction_r_loadi(instruction, process, ram);
  else if (op == i++)
    instruction_r_storei(instruction, process, ram);
  else if (op == i++)
    instruction_r_fork(instruction, process, ram);
  else if (op == i++)
    instruction_r_load(instruction, process, ram);
  else if (op == i++)
    instruction_r_loadi(instruction, process, ram);
  else if (op == i++)
    instruction_r_fork(instruction, process, ram);
  else if (op == i++)
    instruction_r_aff(instruction, process, ram);
  return (RET_SUCCESS);
}

int		instruction_read(t_instruction *instruction,
				 t_process *process, t_ram *ram)
{
  char		op;
  int		i;

  i = 1;
  op = instruction->data[0];
  if (op == i++)
    instruction_r_live(instruction, process, ram);
  else if (op == i++)
    instruction_r_load(instruction, process, ram);
  else if (op == i++)
    instruction_r_store(instruction, process, ram);
  else if (op == i++)
    instruction_r_add(instruction, process, ram);
  else if (op == i++)
    instruction_r_sub(instruction, process, ram);
  else if (op == i++)
    instruction_r_and(instruction, process, ram);
  else if (op == i++)
    instruction_r_or(instruction, process, ram);
  else if (op == i++)
    instruction_r_xor(instruction, process, ram);
  else
    if_tree_2(instruction, process, ram, i);
  return (RET_SUCCESS);
}
