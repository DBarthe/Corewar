/*
** ram_hook_set.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Thu Mar 28 11:00:07 2013 barthelemy delemotte
** Last update Thu Mar 28 11:14:14 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"ram.h"
#include	"op.h"

int		ram_hook_set(t_ram *ram, int idx, int n)
{
  int		i;

  if (ram->hook_set == NULL)
    return (RET_FAILURE);
  i = 0;
  while (i < n)
    {
      ram->hook_set(NULL, ram->last_user_no, (idx + i) % MEM_SIZE);
      i++;
    }
  return (RET_SUCCESS);
}
