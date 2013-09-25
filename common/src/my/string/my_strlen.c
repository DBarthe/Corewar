/*
** my_strlen.c for libmy in /home/raphy/Developement/Libraries/libmy/string
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jan 25 22:41:39 2013 raphael defreitas
** Last update Sat Jan 26 00:52:10 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

int		my_strlen(const char *str)
{
  int		len;

  if (str == NULL)
    return (RET_ERROR);
  len = 0;
  while (str[len])
    len++;
  return (len);
}
