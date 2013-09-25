/*
** my_memset.c for libmy in /home/raphy/Developement/Libraries/libmy/memory
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jan 27 12:32:37 2013 raphael defreitas
** Last update Sun Jan 27 12:34:00 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

int		my_memset(void *ptr, int c, int size)
{
  int		i;
  char		*tmp;

  if (ptr == NULL)
    return (RET_FAILURE);
  tmp = (char *)ptr;
  i = 0;
  while (i < size)
    {
      tmp[i] = c;
      i++;
    }
  return (RET_SUCCESS);
}
