/*
** asm_label.c for asm - corewar in /home/delemo_b/epitech_1/corewar/asm/src/asm
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Wed Mar 20 14:57:49 2013 barthelemy delemotte
** Last update Wed Mar 27 20:07:47 2013 damien sauvalle
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"my.h"

t_label		*label_new(char *name, int idx)
{
  t_label	*label;

  label = xmalloc(sizeof(t_label));
  label->name = my_strdup(name);
  label->idx = idx;
  return (label);
}

void		label_free(t_label *label)
{
  if (label)
    {
      if (label->name)
	free(label->name);
      free(label);
    }
}
