/*
** coffee.c for corewar - asm in /home/delemo_b/epitech_1/corewar/asm/src
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Thu Mar 21 18:57:01 2013 barthelemy delemotte
** Last update Sat Mar 30 14:24:50 2013 damien sauvalle
*/

#include	<stdlib.h>
#include	"my.h"
#include	"asm.h"
#include	"error.h"

static int	check_overflow(int value, int bytes_nbr, int flg)
{
  if (flg == SIGNED)
    {
      if (bytes_nbr == 2 && (value > INT16_MAX || value < INT16_MIN))
	return (RET_FAILURE);
      else if (bytes_nbr == 1 && (value > INT8_MAX || value < INT8_MIN))
	return (RET_FAILURE);
    }
  else if (flg == UNSIGNED)
    if (bytes_nbr == 1 &&
	(value > INT8_MAX_UNSIGNED || value < INT8_MIN_UNSIGNED))
      return (RET_FAILURE);
  return (RET_SUCCESS);
}

int		coffee_write_nbr(char *buff, int value, int bytes_nbr, int flg)
{
  int		i;
  char		*iptr;

  if (buff == NULL || bytes_nbr < 0)
    return (RET_FAILURE);
  if (check_overflow(value, bytes_nbr, flg) == RET_FAILURE)
    return (error_int("Warning: integer overflow\n"));
  i = 0;
  iptr = (char *)&value;
  while (i < bytes_nbr)
    {
      buff[i] = iptr[bytes_nbr - 1 - i];
      i++;
    }
  return (RET_SUCCESS);
}
