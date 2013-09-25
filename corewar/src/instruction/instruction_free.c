/*
** instruction_free.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/instruction
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sat Mar  9 07:29:47 2013 barthelemy delemotte
** Last update Sat Mar  9 07:38:42 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"instruction.h"

void		instruction_free(t_instruction *instruction)
{
  if (instruction)
    {
      if (instruction->data)
	free(instruction->data);
      free(instruction);
    }
}
