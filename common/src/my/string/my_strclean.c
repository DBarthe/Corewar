/*
** my_strclean.c for corewar in /home/sauval_d/corewar/common/src/my/string
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Mon Feb  4 17:39:49 2013 damien sauvalle
** Last update Sun Mar 31 05:04:41 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

int		my_strclean(char *str)
{
  int		i;
  int		j;
  t_bool	cleaned;

  if (str == NULL)
    return (RET_FAILURE);
  cleaned = false;
  j = 0;
  i = 0;
  while (str[i])
    {
      if (!cleaned && (str[i] == '\t' || str[i] == ' '))
	cleaned = true;
      else if (str[i] != '\t' && str[i] != ' ')
	{
	  if (j != 0 && cleaned)
	    str[j++] = ' ';
	  str[j++] = str[i];
	  cleaned = false;
	}
      i++;
    }
  str[j] = '\0';
  return (j);
}
