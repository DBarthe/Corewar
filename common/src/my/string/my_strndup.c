/*
** my_strndup.c for libmy in /home/raphy/Developement/Libraries/libmy/string
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jan 26 21:55:07 2013 raphael defreitas
** Last update Sat Jan 26 21:58:11 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

char		*my_strndup(const char *str, int n)
{
  char		*dup;

  if (str == NULL)
    return (NULL);
  if ((dup = malloc((n + 1) * sizeof(char))) == NULL)
    return (NULL);
  if (my_strncpy(dup, str, n) == RET_FAILURE)
    return (NULL);
  return (dup);
}
