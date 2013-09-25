/*
** params_get_files.c for corewar in /home/raphy/Projects/prog_elem/corewar/corewar/src/params
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jan 31 17:42:51 2013 raphael defreitas
** Last update Sat Mar 16 19:24:35 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	"my.h"
#include	"params.h"
#include	"program.h"
#include	"error.h"

static int	check_a(t_program *prgm, int i, int argc, const char **argv)
{
  if (my_match(argv[i], "-a"))
    {
      if (prgm->load_addr != -1)
	return (error_int(RET_FAILURE, ERR_A_REPEAT));
      if (i + 1 < argc)
        {
          if (!my_str_isnum(argv[i + 1])
	      || (prgm->load_addr = my_getnbr(argv[i + 1])) < 0)
            return (error_int(RET_ERROR, ERR_A_INVALID_VAL));
        }
      else
        return (error_int(RET_FAILURE, ERR_A_NO_VAL));
    }
  return (RET_SUCCESS);
}

static int      check_n(t_program *prgm, int i, int argc, const char **argv)
{
  if (my_match(argv[i], "-n"))
    {
      if (prgm->player_id != -1)
	return (error_int(RET_FAILURE, ERR_N_REPEAT));
      if (i + 1 < argc)
	{
	  if (!my_str_isnum(argv[i + 1])
	      || (prgm->player_id = my_getnbr(argv[i + 1])) < 0)
	    return (error_int(RET_ERROR, ERR_N_INVALID_VAL));
	}
      else
	return (error_int(RET_FAILURE, ERR_N_NO_VAL));
    }
  return (RET_SUCCESS);
}

static int	check_file(t_program *prgm, int i, const char **argv)
{
  int		fd;

  if (argv[i][0] != '-')
    {
      if (i - 1 > 0)
	if (argv[i - 1][0] == '-')
	  return (RET_SUCCESS);
      if ((fd = open(argv[i], O_RDONLY)) == RET_ERROR)
	return (error_int(RET_FAILURE, ERR_FILE_UNEXIST));
      close (fd);
      if ((prgm->file = my_strdup(argv[i])) == NULL)
	return (error_int(RET_FAILURE, ERR_GENERAL));
    }
  return (RET_SUCCESS);
}

static int	fill_program(t_program *program, int i, int argc,
			     const char **argv)
{
  if (check_a(program, i, argc, argv) == RET_FAILURE)
    return (RET_FAILURE);
  if (check_n(program, i, argc, argv) == RET_FAILURE)
    return (RET_FAILURE);
  if (check_file(program, i, argv) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}

int		params_get_files(t_list *programs, int argc,
				 const char **argv)
{
  t_program	*program;
  int		i;

  if ((program = program_new()) == NULL)
    return (error_int(RET_FAILURE, ERR_GENERAL));
  i = 1;
  while (i < argc)
    {
      if (fill_program(program, i, argc, argv) == RET_FAILURE)
	return (RET_FAILURE);
      if (program->file)
	{
	  if (my_list_enqueue(programs, program) == RET_FAILURE)
	    return (error_int(RET_FAILURE, ERR_GENERAL));
	  if (i + 1 < argc && (program = program_new()) == NULL)
	    return (error_int(RET_FAILURE, ERR_GENERAL));
	}
      i++;
    }
  return (RET_SUCCESS);
}
