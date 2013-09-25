/*
** my_calloc.c for libmy in /home/raphy/Developement/Libraries/libmy/memory
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jan 27 12:42:42 2013 raphael defreitas
** Last update Sat Mar 16 19:18:51 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"

void		*my_calloc(int size)
{
  void		*ptr;

  if ((ptr = xmalloc(size)) == NULL)
    return (NULL);
  if (my_memset(ptr, 0, size) == RET_FAILURE)
    return (NULL);
  return (ptr);
}
