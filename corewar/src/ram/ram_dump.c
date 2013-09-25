/*
** ram_dump.c for corewar in /home/delemo_b/epitech_1/corewar/corewar/src
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Fri Mar  8 15:42:27 2013 barthelemy delemotte
** Last update Fri Mar  8 15:53:12 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"ram.h"
#include	"op.h"

int		ram_dump(t_ram *ram)
{
  if (ram == NULL || ram->arena == NULL)
    return (RET_FAILURE);
  my_putstr("Dump memory :\n");
  if (my_memshow(ram->arena, MEM_SIZE) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
