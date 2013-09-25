/*
** process_set_registre.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src/process
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Wed Mar 13 13:21:09 2013 barthelemy delemotte
** Last update Sat Mar 30 13:23:47 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"op.h"
#include	"process.h"

int		process_set_registre(t_process *process, int reg_no, int value)
{
  if (process == NULL)
    return (RET_FAILURE);
  if (reg_no < 1 || reg_no > REG_NUMBER)
    return (RET_FAILURE);
  process->registres[reg_no - 1] = value;
  return (RET_SUCCESS);
}
