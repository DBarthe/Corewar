/*
** program_new.c for vm - corewar in /home/delemo_b/epitech_1/corewar/corewar/src/program
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Jan 28 17:34:33 2013 barthelemy delemotte
** Last update Fri Mar 29 13:12:42 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"program.h"
#include	"my.h"

t_program	*program_new(void)
{
  t_program	*this;

  this = xmalloc(sizeof(t_program));
  if (this == NULL)
    return (NULL);
  this->file = NULL;
  this->player_id = -1;
  this->load_addr = -1;
  this->name = NULL;
  this->data_len = 0;
  this->data = NULL;
  this->code_len = 0;
  this->code = NULL;
  return (this);
}
