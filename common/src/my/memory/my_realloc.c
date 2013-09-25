/*
** my_realloc.c for libmy in /home/raphy/Developement/Libraries/libmy/memory
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jan 27 12:44:01 2013 raphael defreitas
** Last update Sat Mar 16 19:19:03 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"

void		*my_realloc(void *ptr, int old_size, int new_size)
{
  void		*new_ptr;

  if ((new_ptr = xmalloc(new_size)) == NULL)
    return (NULL);
  if (ptr == NULL)
    return (new_ptr);
  if (my_memcpy(new_ptr, ptr, MIN(old_size, new_size)) == RET_FAILURE)
    return (NULL);
  return (new_ptr);
}
