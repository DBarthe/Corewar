/*
** param_label_value.c for corewar in /home/lefebv_z//projet/c-prog-elem/corewar/asm
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Fri Mar 29 14:10:28 2013 marie lefebvre
** Last update Sun Mar 31 15:41:22 2013 damien sauvalle
*/

#include	<stdlib.h>
#include	"my.h"
#include	"asm.h"
#include	"instruction.h"

static t_label	*find_label(t_list *labels, char *param)
{
  t_list_item	*item;
  t_label	*label;

  item = labels->top;
  label = item->data;
  while (item != NULL && my_strcmp(label->name, param) != 0)
    {
      label = item->data;
      item = item->next;
    }
  if (my_strcmp(label->name, param) != 0)
    {
      my_printf("Asm : label %s undefine\n", param);
      return (NULL);
    }
  return (label);
}

int		lab_value(t_list *labels, char *param, t_code *code, int oct_nb)
{
  t_label	*label;
  int		nb;

  if ((label = find_label(labels, param)) == NULL)
    return (RET_FAILURE);
  nb = label->idx - code->idx_line;
  return (coffee_write_nbr(code->str + code->idx, nb, oct_nb, SIGNED));
}
