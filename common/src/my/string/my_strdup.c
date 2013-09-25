/*
** my_strdup.c for libmy in /home/raphy/Developement/Libraries/libmy/string
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jan 26 21:55:07 2013 raphael defreitas
** Last update Sat Jan 26 21:56:37 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

char		*my_strdup(const char *str)
{
  char		*dup;

  if (str == NULL)
    return (NULL);
  if ((dup = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  if (my_strcpy(dup, str) == RET_FAILURE)
    return (NULL);
  return (dup);
}
