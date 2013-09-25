/*
** instruction_load.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/instruction
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Mar 11 10:26:43 2013 barthelemy delemotte
** Last update Tue Mar 19 19:23:18 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"instruction.h"

static int	get_argc(char *poc)
{
  int		i;
  int		argc;

  argc = 0;
  i = 1;
  while (i <= 4)
    {
      if (instruction_get_arg_type(poc, i) != 0)
	argc += 1;
      else
	return (argc);
      i++;
    }
  return (argc);
}

static t_bool	need_poc(char opcode)
{
  if (opcode == 1 || opcode == 9 || opcode == 12 || opcode == 15)
    return (false);
  return (true);
}

static int	set_cycles_to_wait(t_instruction *instruction,
				   t_process *process)
{
  t_op		*op;

  op = op_get_by_opcode(instruction->data[0]);
  if (op == NULL)
    {
      instruction->data[0] = 0;
      process->cycles_to_wait = 1;
      return (RET_FAILURE);
    }
  process->cycles_to_wait = op->nbr_cycles;
  return (RET_SUCCESS);
}

int		instruction_load(t_instruction *instruction,
				 t_process *process, t_ram *ram)
{
  if (instruction == NULL || instruction->data == NULL || process == NULL)
    return (RET_FAILURE);
  if (need_poc(instruction->data[0]) == true)
    {
      instruction->argc = get_argc(instruction->data + 1);
      if (instruction_parse_args(instruction) == RET_ERR_INST)
	{
	  process->cycles_to_wait = 1;
	  instruction->data[0] = 0;
	  return (RET_ERR_INST);
	}
    }
  instruction_read(instruction, process, ram);
  set_cycles_to_wait(instruction, process);
  process->next_instruction = instruction;
  return (RET_SUCCESS);
}
