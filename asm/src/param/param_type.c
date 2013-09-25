/*
** param_type.c for corewar in /home/lefebv_z//projet/c-prog-elem/corewar/asm
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Thu Mar 21 15:20:27 2013 marie lefebvre
** Last update Sat Mar 30 14:26:05 2013 damien sauvalle
*/

#include	<stdlib.h>
#include	"op.h"
#include	"asm.h"
#include	"instruction.h"

static char	*param_type(char *param)
{
  char		*type;
  int		i;

  type = xmalloc(sizeof(char) * 3);
  type[0] = '1';
  type[1] = '1';
  type[2] = '\0';
  i = 0;
  while (param[i] == ' ')
    i++;
  if (param[i] == ' ')
    i++;
  if (param[i] == 'r')
    type[0] = '0';
  if (param[i] == DIRECT_CHAR)
    type[1] = '0';
  return (type);
}

int		param_code_calc(char **instruct, char opcode, char *code)
{
  char		*type;
  char		*param_code;
  int		param_code_nb;
  int		j;

  if (opcode == 1 || opcode == 9 || opcode == 12 || opcode == 15)
    return (RET_SUCCESS);
  param_code = xmalloc(sizeof(char) * 9);
  param_code[0] = '\0';
  j = 1;
  while (instruct[j])
    {
      type = param_type(instruct[j]);
      my_strcat(param_code, type);
      free(type);
      j++;
    }
  while (j++ < 4)
    my_strcat(param_code, "00");
  my_strcat(param_code, "00");
  param_code_nb = my_getnbr_base(param_code, "01");
  free(param_code);
  return (coffee_write_nbr(code, param_code_nb, 1, UNSIGNED));
}
