/*
** ram_new.c for vm - corewar in /home/delemo_b/epitech_1/corewar/corewar/src
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Jan 28 17:08:26 2013 barthelemy delemotte
** Last update Sun Mar 31 11:39:34 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"ram.h"
#include	"my.h"

t_ram		*ram_new(void)
{
  t_ram		*ram;

  ram = xmalloc(sizeof(t_ram));
  if (ram == NULL)
    return (NULL);
  ram->arena = NULL;
  ram->last_user_no = 0;
  return (ram);
}
