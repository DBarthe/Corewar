/*
** process_dup.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Fri Mar  8 17:38:26 2013 barthelemy delemotte
** Last update Fri Mar 15 00:47:20 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"process.h"
#include	"op.h"

t_process	*process_dup(t_process *src, int pid)
{
  t_process	*dst;
  int		i;

  if ((dst = process_new()) == NULL)
    return (NULL);
  dst->pid = pid;
  dst->pc = src->pc;
  if (dst->pc < 0)
    dst->pc += MEM_SIZE;
  dst->carry = src->carry;
  dst->cycles_to_wait = 1;
  dst->next_instruction = NULL;
  i = 0;
  while (i < REG_NUMBER)
    {
      dst->registres[i] = src->registres[i];
      i++;
    }
  return (dst);
}
