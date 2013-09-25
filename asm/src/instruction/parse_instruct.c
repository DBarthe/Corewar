/*
** parse_instruct.c for corewar in /home/lefebv_z//projet/c-prog-elem/corewar/asm
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Wed Mar 20 19:11:52 2013 marie lefebvre
** Last update Thu Mar 28 15:10:36 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	"op.h"
#include	"my.h"
#include	"error.h"
#include	"instruction.h"

static char	*cut_instruct(char *instruction, char cut)
{
  int		i;
  int		len;
  char		*instruct;

  len = 0;
  while (instruction[len] != cut && instruction[len] != '\0')
    len++;
  instruct = xmalloc(sizeof(char) * (len + 1));
  i = 0;
  while (i < len)
    {
      instruct[i] = instruction[i];
      i++;
    }
  instruct[i] = '\0';
  return (instruct);
}

char		**parse_instruct(char *instruction)
{
  char		**instruct;
  char		cut;
  int		ac;
  int		i;
  int		j;

  ac = 2;
  i = 0;
  while (instruction[i])
    if (instruction[i++] == SEPARATOR_CHAR)
      ac++;
  instruct = xmalloc(sizeof(char *) * (ac + 1));
  instruct[0] = cut_instruct(instruction, ' ');
  i = 0;
  j = 1;
  cut = ' ';
  while (j < ac)
    {
      while (instruction[i++] != cut);
      cut = SEPARATOR_CHAR;
      instruct[j++] = cut_instruct(&instruction[i], SEPARATOR_CHAR);
    }
  instruct[j] = '\0';
  return (instruct);
}
