/*
** my_printf.c for libmy in /home/raphy/Developement/Libraries/libmy/standard
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jan 27 16:28:25 2013 raphael defreitas
** Last update Wed Mar 27 14:54:42 2013 raphael defreitas
*/

#include	<stdlib.h>
#include	<stdarg.h>
#include	"my.h"

int		my_printf(const char *format, ...)
{
  int		ret;
  va_list	vl;

  if (format == NULL)
    return (RET_ERROR);
  va_start(vl, format);
  ret = my_vfprintf(STD_OUTPUT, format, &vl);
  va_end(vl);
  return (ret);
}
