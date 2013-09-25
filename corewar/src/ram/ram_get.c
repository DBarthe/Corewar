/*
** ram_get.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/ram
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Mar 11 10:29:48 2013 barthelemy delemotte
** Last update Mon Mar 11 15:05:28 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"ram.h"
#include	"op.h"

char		ram_get(t_ram *ram, int idx)
{
  if (ram == NULL || ram->arena == NULL)
    return (0);
  return (ram->arena[idx % MEM_SIZE]);
}

int		ram_get_n_in_buffer(t_ram *ram, int idx, char *buffer, int n)
{
  int		i;

  if (n < 0 || buffer == NULL)
    return (RET_FAILURE);
  i = 0;
  while (i < n)
    {
      buffer[i] = ram_get(ram, idx + i);
      i++;
    }
  return (RET_SUCCESS);
}
