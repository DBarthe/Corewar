/*
** my_str_isnum.c for corewar in /home/raphy/Projects/prog_elem/corewar/corewar/includes
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Wed Jan 30 22:49:19 2013 raphael defreitas
** Last update Wed Jan 30 23:02:01 2013 raphael defreitas
*/

#include	"my.h"

t_bool		my_str_isnum(const char *str)
{
  int		i;

  i = 0;
  while (str[i] && str[i] == '-' && str[i] == '+')
    i++;
  if (str[i] == '0')
    return (false);
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
        return (false);
      i++;
    }
  return (true);
}
