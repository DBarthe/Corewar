/*
** my_revstr.c for my in /home/raphy/Developement/tmp/corewar/common/src/my/string
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Mar 28 19:20:19 2013 raphael defreitas
** Last update Sat Mar 30 15:52:43 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"

int		my_revstr(char *str)
{
  int		strlen;
  int		i;
  char		tmp;

  if (str == NULL)
    return (RET_FAILURE);
  strlen = my_strlen(str);
  i = 0;
  while (i < strlen / 2)
    {
      tmp = str[i];
      str[i] = str[strlen - i];
      str[strlen - i] = tmp;
      i++;
    }
  return (RET_SUCCESS);
}
