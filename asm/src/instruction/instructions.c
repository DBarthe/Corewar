/*
** new_instruction.c for corewar in /home/lefebv_z//projet/c-prog-elem/corewar/asm
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Tue Mar 26 16:15:24 2013 marie lefebvre
** Last update Sat Mar 30 20:03:44 2013 marie lefebvre
*/

#include	"my.h"
#include	"op.h"
#include	"asm.h"
#include	"instruction.h"

int		find_instruct_code(char **instruct)
{
  int		i;
  int		j;

  i = 0;
  while (my_strcmp(op_tab[i].mnemonique, instruct[0]) != 0)
    i++;
  if (op_tab[i].code == 0)
    {
      my_printf("Asm : Unkown instruction : \n", instruct[0]);
      return (RET_ERROR);
    }
  j = 0;
  while (instruct[j])
    j++;
  if (op_tab[i].nbr_args != (j - 1))
    {
      my_printf("Asm : Bad number of parameters for '%s'\n", instruct[0]);
      return (RET_ERROR);
    }
  return (op_tab[i].code);
}

static int	instruct_param(char **instruct, char opcode,
			       t_code *code, t_list *labels)
{
  if ((param_code_calc(instruct, opcode, code->str + code->idx))
      == RET_FAILURE)
    return (RET_FAILURE);
  if (opcode != 1 && opcode != 9 && opcode != 12 && opcode != 15)
    code->idx += 1;
  if (param_value(labels, instruct, opcode, code) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}

int		instruction(t_list *labels, char *line, t_code *code)
{
  char		**instruct;
  char		opcode;
  int		ret;
  int		ret_param;

  instruct = parse_instruct(line);
  if ((opcode = find_instruct_code(instruct)) == RET_ERROR)
    {
      free_tab(instruct);
      return (RET_FAILURE);
    }
  ret = coffee_write_nbr(code->str + code->idx, (int)opcode, 1, SIGNED);
  if (ret == RET_FAILURE)
    {
      free_tab(instruct);
      return (RET_FAILURE);
    }
  code->idx += 1;
  ret_param = instruct_param(instruct, opcode, code, labels);
  free_tab(instruct);
  return (ret_param);
}
