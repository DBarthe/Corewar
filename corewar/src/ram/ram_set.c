/*
** ram_set.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/ram
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Mar 11 10:29:48 2013 barthelemy delemotte
** Last update Thu Mar 28 11:13:53 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"ram.h"
#include	"op.h"

int		ram_set(t_ram *ram, int idx, char value)
{
  if (ram == NULL || ram->arena == NULL)
    return (RET_FAILURE);
  ram->arena[idx % MEM_SIZE] = value;
  ram_hook_set(ram, idx, 1);
  return (RET_SUCCESS);
}

int		ram_set_n(t_ram *ram, int idx, char *values, int n)
{
  int		i;

  if (n < 0)
    return (RET_FAILURE);
  i = 0;
  while (i < n)
    {
      if (ram_set(ram, idx + i, values[i]) == RET_FAILURE)
	return (RET_FAILURE);
      i++;
    }
  ram_hook_set(ram, idx, n);
  return (RET_SUCCESS);
}

int		ram_set_int32(t_ram *ram, int idx, int value)
{
  int		i;

  if (ram == NULL || ram->arena == NULL)
    return (RET_FAILURE);
  if (idx < 0)
    return (RET_FAILURE);
  i = 3;
  while (i >= 0)
    {
      ram->arena[(idx + i) % MEM_SIZE] = ((char)(value & 0xff));
      value >>= 8;
      i--;
    }
  ram_hook_set(ram, idx, 4);
  return (RET_SUCCESS);
}
