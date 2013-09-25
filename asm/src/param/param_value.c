/*
** param_value.c for corewar in /home/lefebv_z//projet/c-prog-elem/corewar/asm
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Wed Mar 20 19:18:59 2013 marie lefebvre
** Last update Sat Mar 30 15:03:35 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	"my.h"
#include	"op.h"
#include	"error.h"
#include	"asm.h"
#include	"instruction.h"

static int	param_is_nb(char *param, int i)
{
  while (param[i] == '+' || param[i] == '-')
    i++;
  while (param[i] >= '0' && param[i] <= '9')
    i++;
  if (param[i] != '\0')
    {
      my_printf("Asm : %s : Param value isn't a number\n", param);
      return (RET_FAILURE);
    }
  return (RET_SUCCESS);
}

static int	oct_value(t_list *labels, int oct_nb, char *param, t_code *code)
{
  int		nb;
  int		i;

  i = 0;
  while (param[i] == ' ')
    i++;
  if (param[i] == ' ')
    i++;
  if (param[i] == 'r' || param[i] == DIRECT_CHAR)
    i++;
  if (param[i] == LABEL_CHAR)
    return (lab_value(labels, &param[i + 1], code, oct_nb));
  else
    {
      if (param_is_nb(param, i) == RET_FAILURE)
	return (RET_FAILURE);
      nb = unsigned_getnbr_base(&param[i], BASE_DEC);
    }
  return (coffee_write_nbr(code->str + code->idx, nb, oct_nb, SIGNED));
}

int	param_value(t_list *labels, char **instruct, char opcode, t_code *code)
{
  int	i;
  int	oct_nb;

  i = 1;
  while (instruct[i])
    {
      oct_nb = param_oct_nb(instruct[i], i, opcode);
      if (oct_value(labels, oct_nb, instruct[i], code) == RET_FAILURE)
	return (RET_FAILURE);
      code->idx += oct_nb;
      i++;
    }
  return (RET_SUCCESS);
}
