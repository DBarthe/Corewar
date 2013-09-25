/*
** instruction_write.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/instruction/read_write
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Tue Mar 12 19:45:14 2013 barthelemy delemotte
** Last update Sat Mar 30 12:55:51 2013 barthelemy delemotte
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
    instruction_w_zjump(instruction, process, ram);
  else if (op == i++)
    instruction_w_loadi(instruction, process, ram);
  else if (op == i++)
    instruction_w_storei(instruction, process, ram);
  else if (op == i++)
    instruction_w_fork(instruction, process, ram);
  else if (op == i++)
    instruction_w_load(instruction, process, ram);
  else if (op == i++)
    instruction_w_loadi(instruction, process, ram);
  else if (op == i++)
    instruction_w_fork(instruction, process, ram);
  else if (op == i++)
    instruction_w_aff(instruction, process, ram);
  return (RET_SUCCESS);
}

int		instruction_write(t_instruction *instruction,
				  t_process *process, t_ram *ram)
{
  char		op;
  char		i;

  i = 1;
  op = instruction->data[0];
  if (op == i++)
    instruction_w_live(instruction, process, ram);
  else if (op == i++)
    instruction_w_load(instruction, process, ram);
  else if (op == i++)
    instruction_w_store(instruction, process, ram);
  else if (op == i++)
    instruction_w_add(instruction, process, ram);
  else if (op == i++)
    instruction_w_sub(instruction, process, ram);
  else if (op == i++)
    instruction_w_and(instruction, process, ram);
  else if (op == i++)
    instruction_w_or(instruction, process, ram);
  else if (op == i++)
    instruction_w_xor(instruction, process, ram);
  else
    if (if_tree_2(instruction, process, ram, i));
  return (RET_SUCCESS);
}
