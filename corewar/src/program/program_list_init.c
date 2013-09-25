/*
** program_list_init.c for vm - corewar in /home/delemo_b/epitech_1/corewar/corewar/src/program
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Feb  4 17:51:30 2013 barthelemy delemotte
** Last update Sat Mar 30 14:15:52 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"program.h"
#include	"my.h"
#include	"error.h"

static t_bool	is_collision(t_program *p1, t_program *p2)
{
  if (p2->load_addr >= p1->load_addr &&
      p2->load_addr <= p1->load_addr + p1->code_len)
    {
      return (true);
    }
  else if (p2->load_addr + p2->code_len  >= p1->load_addr &&
      p2->load_addr + p2->code_len <= p1->load_addr + p1->code_len)
    {
      return (true);
    }
  return (false);
}

static t_bool	check_conflicts(t_list *programs)
{
  t_list_item	*item;
  t_list_item	*sec_it;
  t_program	*program;
  t_program	*sec_prog;

  item = programs->top;
  while (item)
    {
      program = (t_program *)item->data;
      sec_it = programs->top;
      while (sec_it)
	{
	  if (sec_it != item)
	    {
	      sec_prog = (t_program *)sec_it->data;
	      if (is_collision(program, sec_prog) == true)
		return (true);
	    }
	  sec_it = sec_it->next;
	}
      item = item->next;
    }
  return (false);
}

static int	check_load_addr(t_list *programs)
{
  t_list_item	*item;
  t_program	*program;
  int		ld_addr;

  ld_addr = 0;
  item = programs->top;
  while (item)
    {
      program = (t_program *)item->data;
      if (program->load_addr != -1)
	ld_addr++;
      item = item->next;
    }
  if (ld_addr > 0 && ld_addr != programs->length)
    return (error_int(RET_FAILURE, ERR_UNDEF_LDA));
  if (ld_addr > 0 && check_conflicts(programs) == true)
    return (error_int(RET_FAILURE, ERR_CONFLICT_DATA));
  return (RET_SUCCESS);
}

int		program_list_init(t_list *programs)
{
  t_list_item	*item;
  t_program	*program;

  if (program_load_datas(programs) == RET_FAILURE)
    return (RET_FAILURE);
  if (check_load_addr(programs) == RET_FAILURE)
    return (RET_FAILURE);
  if (program_init_load_addr(programs) == RET_FAILURE)
    return (RET_FAILURE);
  program_attrib_id(programs);
  item = programs->top;
  while (item)
    {
      program = (t_program *)item->data;
      if (program_init_name(program) == RET_FAILURE)
	return (RET_FAILURE);
      item = item->next;
    }
  return (RET_SUCCESS);
}
