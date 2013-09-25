/*
** my_strchr.c for libmy in /home/raphy/Developement/Libraries/libmy/string
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jan 26 22:00:04 2013 raphael defreitas
** Last update Sat Jan 26 22:04:56 2013 raphael defreitas
*/

#include	<stdlib.h>

const char	*my_strchr(const char *str, int c)
{
  int		i;

  if (str == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (str + i * sizeof(char));
      i++;
    }
  return (NULL);
}
