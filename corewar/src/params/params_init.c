/*
** params_init.c for corewar in /home/raphy/Projects/prog_elem/corewar/corewar/src/params
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Wed Jan 30 21:05:38 2013 raphael defreitas
** Last update Sat Mar 30 22:44:30 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"params.h"
#include	"program.h"
#include	"error.h"

static t_bool	is_in_tab(char **tab, const char *str)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      if (my_match(str, tab[i]))
	return (true);
      i++;
    }
  return (false);
}

static t_bool	is_allowed_params(int argc, const char **argv)
{
  char		**allowed_params;
  int		i;

  if (my_explode(&allowed_params, PARAMS_ALLOWED, " ") == RET_ERROR)
    return (false);
  i = 1;
  while (i < argc)
    {
      if (argv[i][0] == '-')
	{
	  if (!is_in_tab(allowed_params, argv[i]))
	    {
	      free(allowed_params);
	      return (error_bool(false, ERR_INVALID_PARAMS));
	    }
	}
      i++;
    }
  free(allowed_params);
  return (true);
}

int		params_init(t_params *params, int argc, const char **argv)
{
  if (params == NULL || argv == NULL)
    return (RET_FAILURE);
  if ((params->dump_cycle = params_get_dump_cycle(argc, argv)) == RET_ERROR)
    return (RET_FAILURE);
  if (params_get_files(params->programs, argc, argv) == RET_FAILURE)
    return (RET_FAILURE);
  if (!is_allowed_params(argc, argv))
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
