/*
** main.c for corewar in /home/raphy/Projects/prog_elem/corewar/corewar
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jan 27 17:43:51 2013 raphael defreitas
** Last update Fri Apr  5 18:08:28 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"params.h"
#include	"brain.h"
#include	"ram.h"

static t_params	*corewar_init(int argc, const char **argv)
{
  t_params	*params;

  if ((params = params_new()) == NULL)
    return (NULL);
  if (params_init(params, argc, argv) == RET_FAILURE)
    return (NULL);
  if (params_check_double_id(params) == RET_FAILURE)
    return (NULL);
  return (params);
}

int		main(int argc, const char **argv)
{
  t_params	*params;
  t_brain      	*brain;
  int		ret;

  if ((params = corewar_init(argc, argv)) == NULL ||
      (brain = brain_new()) == NULL)
    return (0);
  if (brain_load(brain, params) == RET_FAILURE)
    {
      brain_free(brain);
      return (0);
    }
  params_free(params);
  ret = brain_run(brain);
  if (ret != RET_ERROR)
    brain_free(brain);
  return (ret < 0 ? 0 : ret);
}
