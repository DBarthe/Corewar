/*
** error.c for corewar in /home/lefebv_z//projet/corewar/asm
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Thu Jan 31 17:56:53 2013 marie lefebvre
** Last update Thu Mar 21 18:40:11 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	"my.h"

void		*error_ptr(const char *mess)
{
  my_fputstr(2, "Asm: ");
  my_fputstr(2, mess);
  return (NULL);
}

int		error_int(const char *mess)
{
  my_fputstr(2, "Asm: ");
  my_fputstr(2, mess);
  return (RET_FAILURE);
}

int		v_error_int(const char *mess, int ret_value)
{
  my_fputstr(2, "Asm: ");
  my_fputstr(2, mess);
  return (ret_value);
}
