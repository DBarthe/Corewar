/*
** params_get_dump_cycle.c for corewar in /home/raphy/Projects/prog_elem/corewar/corewar/src/params
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Wed Jan 30 22:19:55 2013 raphael defreitas
** Last update Sat Mar 16 19:23:21 2013 barthelemy delemotte
*/

#include	"my.h"
#include	"error.h"
#include	"game.h"

int		params_get_dump_cycle(int argc, const char **argv)
{
  int		i;
  int		dump_cycle;

  dump_cycle = DUMP_UNDEF;
  i = 1;
  while (i < argc)
    {
      if (my_match(argv[i], "-dump"))
	{
	  if (dump_cycle != DUMP_UNDEF)
	    return (error_int(RET_ERROR, ERR_DUMP_REPEAT));
	  if (i + 1 < argc)
	    {
	      if (!my_str_isnum(argv[i + 1])
		  || (dump_cycle = my_getnbr(argv[i + 1])) < 0)
		return (error_int(RET_ERROR, ERR_DUMP_INVALID_VAL));
	    }
	  else
	    return (error_int(RET_ERROR, ERR_DUMP_NO_VAL));
	}
      i++;
    }
  return (dump_cycle);
}
