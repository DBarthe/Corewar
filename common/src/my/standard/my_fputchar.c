/*
** my_fputchar.c for libmy in /home/raphy/Developement/Libraries/libmy/standard
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jan 25 22:43:07 2013 raphael defreitas
** Last update Sun Jan 27 22:45:55 2013 raphael defreitas
*/

#include	<unistd.h>
#include	"my.h"

int		my_fputchar(const int fd, int c)
{
  int		ret;

  if ((ret = write(fd, &c, 1)) == RET_ERROR)
    if (write(ERR_OUTPUT, "my_fputchar: cannot write.\n", 27) == RET_ERROR)
      return (RET_ERROR);
  return (ret);
}
