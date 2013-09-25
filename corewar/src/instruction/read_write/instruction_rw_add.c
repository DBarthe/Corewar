/*
** instruction_rw_add.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/instruction/read_write
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Mar 11 18:40:32 2013 barthelemy delemotte
** Last update Sat Mar 30 12:49:34 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"instruction.h"
#include	"process.h"

int		instruction_r_add(t_instruction *instruction,
				  t_process *process, t_ram *ram)
{
  return (instruction_r_op(instruction, process, ram));
}

int		instruction_w_add(t_instruction *instruction,
				  t_process *process, t_ram *ram)
{
  int		res;

  res = instruction->argv[0] + instruction->argv[1];
  process_set_registre(process, instruction->argv[2], res);
  process->carry = (res == 0 ? 1 : 0);
  return (RET_SUCCESS);
}
