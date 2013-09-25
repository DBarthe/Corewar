/*
** my_strstr.c for libmy in /home/raphy/Developement/Libraries/libmy/string
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jan 26 22:04:39 2013 raphael defreitas
** Last update Sun Jan 27 12:21:24 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

const char	*my_strstr(const char *haystack, const char *needle)
{
  const char	*tmp;

  if (haystack == NULL || needle == NULL)
    return (NULL);
  tmp = haystack;
  while ((tmp = my_strchr(tmp, *needle)))
    {
      if (my_strncmp(tmp, needle, my_strlen(needle)) == 0)
	return (tmp);
      tmp = tmp + sizeof(char);
    }
  return (NULL);
}
