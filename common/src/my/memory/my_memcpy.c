/*
** my_memcpy.c for libmy in /home/raphy/Developement/Libraries/libmy/memory
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jan 27 12:34:15 2013 raphael defreitas
** Last update Sun Jan 27 12:41:52 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

int		my_memcpy(void *dest, const void *src, int size)
{
  int		i;
  char		*dest_tmp;
  const char	*src_tmp;

  if (dest == NULL || src == NULL)
    return (RET_FAILURE);
  dest_tmp = (char *)dest;
  src_tmp = (char *)src;
  i = 0;
  while (i < size)
    {
      dest_tmp[i] = src_tmp[i];
      i++;
    }
  return (RET_SUCCESS);
}
