/*
** params_check_double_id.c for corewar - vm in /home/delemo_b/corewar-2017-sauval_d/corewar/src/params
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sun Mar 31 20:14:20 2013 barthelemy delemotte
** Last update Sun Mar 31 20:28:34 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"params.h"
#include	"program.h"
#include	"error.h"

static int	check_double_id(t_program *program, t_list *programs)
{
  t_list_item	*item;
  t_program	*test_prgm;
  int		id;

  id = program->player_id;
  item = programs->top;
  while (item)
    {
      test_prgm = item->data;
      if (test_prgm != program)
	{
	  if (id == test_prgm->player_id)
	    return (RET_FAILURE);
	}
      item = item->next;
    }
  return (RET_SUCCESS);
}

int		params_check_double_id(t_params *params)
{
  t_list_item	*item;
  t_program	*program;

  if (params == NULL)
    return (RET_FAILURE);
  item = params->programs->top;
  while (item)
    {
      program = item->data;
      if (program->player_id > 0 &&
	  check_double_id(program, params->programs) == RET_FAILURE)
	return (error_int(RET_FAILURE, ERR_N_REPEAT));
      item = item->next;
    }
  return (RET_SUCCESS);
}
