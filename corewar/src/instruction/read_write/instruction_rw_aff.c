/*
** instruction_rw_aff.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/instruction/read_write
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Tue Mar 12 11:21:32 2013 barthelemy delemotte
** Last update Fri Mar 29 12:44:22 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"op.h"
#include	"instruction.h"

int		instruction_r_aff(t_instruction *instruction,
				   t_process *process, t_ram *ram)
{
  if (instruction == NULL || process == NULL)
    return (RET_FAILURE);
  (void)ram;
  instruction->argv[0] = instruction_get_val_reg(instruction->data + 2,
						 REG_SIZE, process);
  return (RET_SUCCESS);
}

int		instruction_w_aff(t_instruction *instruction,
				   t_process *process, t_ram *ram)
{
  (void)ram;
  (void)process;
  my_putchar((char)(instruction->argv[0] % 256));
  return (RET_SUCCESS);
}
