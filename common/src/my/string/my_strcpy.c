/*
** my_strcpy.c for libmy in /home/raphy/Developement/Libraries/libmy/string
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jan 26 21:39:54 2013 raphael defreitas
** Last update Sat Jan 26 21:42:43 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

int		my_strcpy(char *dest, const char *src)
{
  int		i;

  if (dest == NULL || src == NULL)
    return (RET_FAILURE);
  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (RET_SUCCESS);
}
