/*
** process_get_registre.c for corewar - vm  in /home/delemo_b/epitech_1/corewar/corewar/src/process
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Mar 11 17:51:50 2013 barthelemy delemotte
** Last update Wed Mar 13 17:20:39 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"op.h"
#include	"process.h"

int		process_get_registre(t_process *process, int reg_no)
{
  if (process == NULL)
    return (0);
  if (reg_no < 1 || reg_no > REG_NUMBER)
    return (0);
  return (process->registres[reg_no - 1]);
}
