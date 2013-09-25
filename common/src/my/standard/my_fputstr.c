/*
** my_fputstr.c for libmy in /home/raphy/Developement/Libraries/libmy/standard
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jan 25 22:53:33 2013 raphael defreitas
** Last update Sun Jan 27 22:45:21 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

int		my_fputstr(const int fd, const char *str)
{
  int		ret;

  if (str == NULL)
    return (RET_ERROR);
  if ((ret = write(fd, str, my_strlen(str))) == RET_ERROR)
    if (write(ERR_OUTPUT, "my_fputstr: cannot write.\n", 26) == RET_ERROR)
      return (RET_ERROR);
  return (ret);
}
