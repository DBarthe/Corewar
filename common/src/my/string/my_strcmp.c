/*
** my_strcmp.c for libmy in /home/raphy/Developement/Libraries/libmy/string
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jan 26 22:06:54 2013 raphael defreitas
** Last update Sat Jan 26 22:09:05 2013 raphael defreitas
*/

#include	<stdlib.h>

int		my_strcmp(const char *str1, const char *str2)
{
  int		i;

  if (str1 == NULL || str2 == NULL)
    return (0);
  i = 0;
  while (str1[i] && str2[i] && str1[i] == str2[i])
    i++;
  return (str1[i] - str2[i]);
}
