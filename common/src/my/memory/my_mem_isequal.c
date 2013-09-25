/*
** my_mem_isequal.c for libmy in /home/raphy/Developement/Libraries/libmy/memory
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jan 27 12:39:19 2013 raphael defreitas
** Last update Sun Jan 27 12:41:19 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

t_bool		my_mem_isequal(const void *ptr1, const void *ptr2, int size)
{
  int		i;
  const char	*tmp1;
  const char	*tmp2;

  if (ptr1 == NULL || ptr2 == NULL)
    return (false);
  tmp1 = (char *)ptr1;
  tmp2 = (char *)ptr2;
  i = 0;
  while (i < size)
    {
      if (tmp1[i] != tmp2[i])
	return (false);
      i++;
    }
  return (true);
}
