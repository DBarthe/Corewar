/*
** instruction_error.c for corewar in /home/lefebv_z//projet/c-prog-elem/corewar/asm/src/asm
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Mon Mar 25 14:03:56 2013 marie lefebvre
** Last update Thu Mar 28 15:38:23 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	"op.h"
#include	"my.h"

int		instruction_error(char *line)
{
  int		i;

  i = 0;
  while (line[i] != '\0' && line[i] != ' ')
    i++;
  if (line[i] != ' ')
    return (RET_FAILURE);
  while (line[i])
    {
      if (line[i] == SEPARATOR_CHAR
	  && (line[i + 1] == SEPARATOR_CHAR || line[i + 1] == '\0'))
	return (RET_FAILURE);
      i++;
    }
  return (RET_SUCCESS);
}
