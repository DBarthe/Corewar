/*
** error.c for corewar in /home/raphy/Projects/prog_elem/corewar/corewar/src
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Wed Jan 30 22:16:59 2013 raphael defreitas
** Last update Wed Mar 27 16:41:27 2013 raphael defreitas
*/

#include	<stdarg.h>
#include	"my.h"

int		error_int(int code, const char *msg, ...)
{
  va_list	vl;

  va_start(vl, msg);
  my_fputstr(ERR_OUTPUT, "[ERROR] ");
  my_vfprintf(ERR_OUTPUT, msg, &vl);
  my_fputchar(ERR_OUTPUT, '\n');
  va_end(vl);
  return (code);
}

void		*error_ptr(void *ptr, const char *msg, ...)
{
  va_list	vl;

  va_start(vl, msg);
  my_fputstr(ERR_OUTPUT, "[ERROR] ");
  my_vfprintf(ERR_OUTPUT, msg, &vl);
  my_fputchar(ERR_OUTPUT, '\n');
  va_end(vl);
  return (ptr);
}

t_bool		error_bool(t_bool val, const char *msg, ...)
{
  va_list	vl;

  va_start(vl, msg);
  my_fputstr(ERR_OUTPUT, "[ERROR] ");
  my_vfprintf(ERR_OUTPUT, msg, &vl);
  my_fputchar(ERR_OUTPUT, '\n');
  va_end(vl);
  return (val);
}
