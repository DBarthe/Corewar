/*
** instruct_len.c for corewar in /home/lefebv_z//projet/c-prog-elem/corewar/asm
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Thu Mar 21 18:36:20 2013 marie lefebvre
** Last update Sun Mar 31 11:03:51 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"error.h"
#include	"instruction.h"

static int	instruct_len(int code, int len, char **instruct)
{
  int		i;

  if (code != 1 && code != 9 && code != 12 && code != 15)
    len++;
  i = 1;
  while (instruct[i])
    {
      len += param_oct_nb(instruct[i], i, code);
      i++;
    }
  free_tab(instruct);
  return (len);
}

int		instruction_get_len(char *line)
{
  char		**instruct;
  int		len;
  int		code;

  if (line == NULL || line[0] == '\0')
    return (0);
  if (instruction_error(line) == RET_FAILURE)
    return (v_error_int("Error syntax on line\n", RET_ERROR));
  instruct = parse_instruct(line);
  len = 1;
  if ((code = find_instruct_code(instruct)) == RET_ERROR)
    {
      free_tab(instruct);
      return (RET_ERROR);
    }
  return (instruct_len(code, len, instruct));
}
