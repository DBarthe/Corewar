/*
** my_strpos.c for libmy in /home/raphy/Developement/Libraries/libmy/string
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jan 26 01:16:53 2013 raphael defreitas
** Last update Sat Jan 26 01:18:42 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

int		my_strpos(const char *str, int c)
{
  int		i;

  if (str == NULL)
    return (RET_ERROR);
  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (i);
      i++;
    }
  return (RET_ERROR);
}
