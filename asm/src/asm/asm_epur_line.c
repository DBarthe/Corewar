/*
** asm_epur_line.c for corewar in /home/lefebv_z//projet/c-prog-elem/corewar/asm
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Sat Mar 30 14:40:51 2013 marie lefebvre
** Last update Sat Mar 30 14:44:29 2013 marie lefebvre
*/

#include	"my.h"

static void	del_case(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      str[i] = str[i + 1];
      i++;
    }
}

void		epur_line_of_label(char *line)
{
  while (line[0] != ' ' && line[0] != '\0')
    del_case(line);
  while (line[0] == ' ')
    del_case(line);
}

int		clean_line(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0' && str[i] != ' ')
    i++;
  if (str[i] == '\0')
    return (RET_SUCCESS);
  i++;
  while (str[i] != '\0' && str[i] != ' ')
    i++;
  while (str[i])
    {
      if (str[i] == ' ')
	del_case(str + i);
      else
	i++;
    }
  return (RET_SUCCESS);
}
