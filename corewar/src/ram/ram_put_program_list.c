/*
** ram_put_program_list.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Fri Mar  8 15:23:28 2013 barthelemy delemotte
** Last update Fri Mar  8 15:26:58 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"ram.h"
#include	"program.h"

int		ram_put_program_list(t_ram *ram, t_list *program_list)
{
  t_list_item	*item;
  t_program	*p;

  if (ram == NULL || program_list == NULL)
    return (RET_FAILURE);
  item = program_list->top;
  while (item)
    {
      p = (t_program *)item->data;
      if (p != NULL)
	{
	  ram_put_program(ram, p);
	}
      item = item->next;
    }
  return (RET_SUCCESS);
}
