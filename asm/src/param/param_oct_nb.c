/*
** param_oct_nb.c for corewar in /home/lefebv_z//projet/c-prog-elem/corewar/asm
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Wed Mar 20 19:14:23 2013 marie lefebvre
** Last update Sun Mar 31 17:54:59 2013 damien sauvalle
*/

#include	<stdlib.h>
#include	"op.h"
#include	"instruction.h"

static int	oct_nb_except(char *param, int i, char code)
{
  if (i == 1)
    {
      if (code == 1)
	return (4);
      else if (code == 11)
	return (1);
      else
	return (IND_SIZE);
    }
  else if (i == 3)
    {
      if (code == 10 || code == 14)
	return (1);
      else
	return (IND_SIZE);
    }
  return (IND_SIZE);
}

static int	exception_eleven(char *param, int i, char code, int oct_nb)
{
  int		j;

  j = 0;
  while (param[j] == ' ')
    j++;
  if (param[j] == ' ')
    j++;
  if (param[j] == 'r')
    {
      if (i == 2 || i == 3)
      	oct_nb = 1;
    }
  return (oct_nb);
}

int		param_oct_nb(char *param, int i, char code)
{
  int		oct_nb;
  int		j;

  if (code == 1 || code == 9 || code == 10 || code == 11
      || code == 12 || code == 14 || code == 15)
    oct_nb = oct_nb_except(param, i, code);
  else
    {
      j = 0;
      while (param[j] == ' ')
	j++;
      if (param[j] == ' ')
	j++;
      if (param[j] == 'r')
	oct_nb = 1;
      else if (param[j] == DIRECT_CHAR)
	oct_nb = DIR_SIZE;
      else
	oct_nb = IND_SIZE;
    }
    if (code == 11 && ((i == 2) || (i == 3)))
      oct_nb = exception_eleven(param, i, code, oct_nb);
    return (oct_nb);
}
