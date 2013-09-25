/*
** instruction_parse_args.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/instruction
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Mar 11 17:02:34 2013 barthelemy delemotte
** Last update Mon Mar 11 17:09:06 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"op.h"
#include	"instruction.h"

int		instruction_parse_args(t_instruction *instruction)
{
  t_op		*op;
  int		i;

  if ((op = op_get_by_opcode(instruction->data[0])) == NULL)
    return (RET_ERR_INST);
  if (instruction->argc != op->nbr_args)
    return (RET_ERR_INST);
  i = 0;
  while (i < instruction->argc)
    {
      if ((instruction_get_arg_type(instruction->data + 1, i + 1)
	   & op->type[i]) == 0)
	return (RET_ERR_INST);
      i++;
    }
  return (RET_SUCCESS);
}
