/*
** ram_free.c for vm - corewar in /home/delemo_b/epitech_1/corewar/corewar/src/ram
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Jan 28 17:19:30 2013 barthelemy delemotte
** Last update Mon Jan 28 17:20:39 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"ram.h"

void		ram_free(t_ram *ram)
{
  if (ram != NULL)
    {
      if (ram->arena != NULL)
	free(ram->arena);
      free(ram);
    }
}
