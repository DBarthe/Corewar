/*
** asm_fill_len_and_labels.c for corewar in /home/sauval_d//corewar/asm/src/asm
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Mon Mar 25 14:38:43 2013 damien sauvalle
** Last update Sun Mar 31 09:53:58 2013 damien sauvalle
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"instruction.h"
#include	"error.h"
#include	"my.h"
#include	"op.h"

static char	*recup_label(char *line, t_asm *asm_d)
{
  int		i;
  char		*label;

  i = 0;
  while (line[i] != ' ' && line[i] != '\0')
    i++;
  if (line[i - 1] == LABEL_CHAR)
    {
      label = xmalloc(sizeof(char) * (i + 1));
      label[0] = '\0';
      my_strncpy(label, line, i - 1);
      epur_line_of_label(line);
      return (label);
    }
  return (NULL);
}

static int	check_label(char *label)
{
  int		i;
  int		j;
  int		f;

  f = 0;
  i = 0;
  while (label[i])
    {
      j = 0;
      while (LABEL_CHARS[j])
	if (LABEL_CHARS[j++] == label[i])
	  f = 1;
      if (f == 0)
	{
	  my_printf("Label: \"%s\" is invalid\n", label);
	  return (-1);
	}
      f = 0;
      i++;
    }
  return (0);
}

int		asm_fill_len_and_labels(t_asm *asm_d)
{
  t_list_item	*item;
  t_label	*labs;
  char		*line;
  int		tmp_len;
  char		*label;

  item = asm_d->file->top;
  while (item != NULL)
    {
      line = item->data;
      label = recup_label(line, asm_d);
      if (label != NULL && check_label(label) == 0)
	{
	  labs = label_new(label, asm_d->code_len);
	  my_list_enqueue(asm_d->labels, labs);
	}
      if ((tmp_len = instruction_get_len(line)) == RET_ERROR)
	return (RET_FAILURE);
      clean_line(line);
      item->data = line;
      asm_d->code_len += tmp_len;
      item = item->next;
      free(label);
    }
  return (RET_SUCCESS);
}
