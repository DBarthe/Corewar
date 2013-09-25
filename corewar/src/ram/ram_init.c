/*
** ram_init.c for vm - corewar in /home/delemo_b/epitech_1/corewar/corewar/src/ram
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sat Feb  2 16:53:13 2013 barthelemy delemotte
** Last update Sat Mar 30 16:56:43 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"ram.h"
#include	"my.h"

int		ram_init(t_ram *ram, int mem_size)
{
  ram->arena = xmalloc(mem_size * sizeof(char));
  if (ram->arena == NULL)
    return (RET_FAILURE);
  ram->hook_set = NULL;
  return (RET_SUCCESS);
}
