/*
** cleaner.c for corewar in /home/sauval_d//corewar/asm/src/parser
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Mon Feb  4 13:16:08 2013 damien sauvalle
** Last update Sat Mar 30 12:59:21 2013 damien sauvalle
*/

#include	"parser.h"
#include	"my.h"
#include	"op.h"

static char	*edit_line(char *line)
{
  int		i;

  i = 0;
  while (line[i] && line[i] != COMMENT_CHAR)
    i++;
  line[i] = '\0';
  return (line);
}

static t_bool	check_line_empty(char *line)
{
  if (line[0] == '\0')
    return (true);
  else
    return (false);
}

int		remove_comment(t_list *file)
{
  t_list_item	*tmp;
  t_list_item	*to_delete;

  tmp = file->top;
  while (tmp)
    {
      edit_line(tmp->data);
      my_strclean(tmp->data);
      if (check_line_empty(tmp->data) == true)
	{
	  to_delete = tmp;
	  tmp = tmp->next;
	  my_list_delete(file, to_delete);
	}
      else
	tmp = tmp->next;
    }
  return (RET_SUCCESS);
}
