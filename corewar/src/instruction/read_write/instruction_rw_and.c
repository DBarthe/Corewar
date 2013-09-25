/*
** instruction_rw_and.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/instruction/read_write
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Mar 11 18:45:20 2013 barthelemy delemotte
** Last update Sat Mar 30 12:50:32 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"instruction.h"
#include	"process.h"

int		instruction_r_and(t_instruction *instruction,
				  t_process *process, t_ram *ram)
{
  return (instruction_r_op_b(instruction, process, ram));
}

int		instruction_w_and(t_instruction *instruction,
				  t_process *process, t_ram *ram)
{
  int		res;

  res = instruction->argv[0] & instruction->argv[1];
  process_set_registre(process, instruction->argv[2], res);
  process->carry = (res == 0 ? 1 : 0);
  return (RET_SUCCESS);
}
