/*
** program_init_name.c for vm - corewar in /home/delemo_b/epitech_1/corewar/corewar/src/program
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Feb  4 17:39:52 2013 barthelemy delemotte
** Last update Wed Mar 13 12:57:23 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"program.h"
#include	"my.h"
#include	"op.h"
#include	"error.h"

int		program_init_name(t_program *program)
{
  if (program->data == NULL)
    return (RET_FAILURE);
  if ((program->name = my_calloc((PROG_NAME_LENGTH + 1)
				 * sizeof(char))) == NULL)
    return (error_int(RET_FAILURE, ERR_MALLOC));
  my_strncpy(program->name, program->data + MAGIC_LEN, PROG_NAME_LENGTH);
  return (RET_SUCCESS);
}
