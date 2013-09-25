/*
** my_match.c for libmy in /home/raphy/Developement/Libraries/libmy/string
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jan 26 21:44:54 2013 raphael defreitas
** Last update Sat Jan 26 21:46:01 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	"my.h"

t_bool		my_match(const char *str, const char *pattern)
{
  if (str == NULL || pattern == NULL)
    return (false);
  if (*pattern != '*')
    {
      if (*str)
	return (*str == *pattern
		&& my_match(str + sizeof(char), pattern + sizeof(char)));
      else
	return (!*pattern);
    }
  return (my_match(str, pattern + sizeof(char))
	  || (*str && my_match(str + sizeof(char), pattern)));
}
