/*
** instruction_new.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/instruction
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sat Mar  9 07:29:51 2013 barthelemy delemotte
** Last update Sat Mar 16 19:14:24 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"instruction.h"
#include	"error.h"

t_instruction	*instruction_new(char *data, int data_len)
{
  t_instruction	*instruction;
  int		i;

  if (data == NULL)
    return (NULL);
  if ((instruction = xmalloc(sizeof(t_instruction))) == NULL)
    return (error_ptr(NULL, ERR_MALLOC));
  instruction->data = data;
  instruction->data_len = data_len;
  instruction->argc = ARGC_UNDEF;
  i = 0;
  while (i < ARGC_UNDEF)
    {
      instruction->argv[i] = 0;
      i++;
    }
  return (instruction);
}
