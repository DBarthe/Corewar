/*
** program_attrib_id.c for vm - corewar in /home/delemo_b/epitech_1/corewar/corewar/src/program
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Feb  4 19:59:06 2013 barthelemy delemotte
** Last update Sat Mar 30 14:13:31 2013 barthelemy delemotte
*/

#include	"program.h"
#include	"my.h"

static int	find_new_id(t_list_item *top)
{
  t_list_item	*cur;
  t_program	*program;
  int		id;
  int		diff;

  id = 0;
  diff = 0;
  while (!diff)
    {
      id++;
      cur = top;
      diff = 1;
      while (cur)
	{
	  program = (t_program *)cur->data;
	  if (program->player_id == id)
	    diff = 0;
	  cur = cur->next;
	}
    }
  return (id);
}

int		program_attrib_id(t_list *programs)
{
  t_list_item	*item;
  t_program	*program;

  item = programs->top;
  while (item)
    {
      program = (t_program *)item->data;
      if (program->player_id == -1)
	program->player_id = find_new_id(programs->top);
      item = item->next;
    }
  return (RET_SUCCESS);
}
