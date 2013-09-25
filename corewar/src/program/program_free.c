/*
** program_free.c for vm - corewar in /home/delemo_b/epitech_1/corewar/corewar/src/program
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Jan 28 17:34:21 2013 barthelemy delemotte
** Last update Fri Mar  8 16:24:30 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"program.h"

void		program_free(t_program *program)
{
  if (program != NULL)
    {
      if (program->file != NULL)
	free(program->file);
      if (program->name != NULL)
	free(program->name);
      if (program->data != NULL)
	free(program->data);
      free(program);
    }
}
