/*
** program_init_load_addr.c for vm - corewar in /home/delemo_b/epitech_1/corewar/corewar/src/program
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Fri Feb  1 15:21:08 2013 barthelemy delemotte
** Last update Sat Mar 30 14:14:36 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"program.h"
#include	"op.h"
#include	"my.h"
#include	"error.h"

static int	get_data_len_sum(t_list *programs)
{
  int		sum;
  t_list_item	*item;
  t_program	*program;

  sum = 0;
  item = programs->top;
  while (item)
    {
      program = (t_program *)item->data;
      sum += program->code_len;
      item = item->next;
    }
  return (sum);
}

int		program_init_load_addr(t_list *programs)
{
  t_program	*program;
  t_list_item	*item;
  int		distance;
  int		cur_addr;

  item = programs->top;
  if (programs->length == 0)
    return (error_int(RET_FAILURE, ERR_NO_PRGM));
  distance = (MEM_SIZE - get_data_len_sum(programs)) /  programs->length;
  if (distance < 0)
    return (error_int(RET_FAILURE, ERR_TOO_LONG_PRGM));
  cur_addr = 0;
  while (item != NULL)
    {
      program = (t_program *)item->data;
      if (program->load_addr == -1)
	{
	  program->load_addr = cur_addr;
	  cur_addr += program->code_len + distance;
	}
      item = item->next;
    }
  return (RET_SUCCESS);
}
