/*
** my_strncmp.c for libmy in /home/raphy/Developement/Libraries/libmy/string
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jan 26 22:06:54 2013 raphael defreitas
** Last update Sun Jan 27 12:18:31 2013 raphael defreitas
*/

#include	<stdlib.h>

int		my_strncmp(const char *str1, const char *str2, int n)
{
  int		i;

  if (str1 == NULL || str2 == NULL)
    return (0);
  i = 0;
  while (str1[i] && str2[i] && str1[i] == str2[i] && i < n - 1)
    i++;
  return (str1[i] - str2[i]);
}
