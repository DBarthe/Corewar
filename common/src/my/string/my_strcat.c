/*
** my_strcat.c for libmy in /home/raphy/Developement/Libraries/libmy/string
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jan 26 21:48:46 2013 raphael defreitas
** Last update Sat Jan 26 21:51:23 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

int		my_strcat(char *dest, const char *src)
{
  int		i;
  int		dest_len;

  if (dest == NULL || src == NULL)
    return (RET_FAILURE);
  dest_len = my_strlen(dest);
  i = 0;
  while (src[i])
    {
      dest[dest_len + i] = src[i];
      i++;
    }
  dest[dest_len + i] = '\0';
  return (RET_SUCCESS);
}
