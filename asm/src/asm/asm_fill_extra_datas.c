/*
** asm_fill_extra_datas.c for corewar - vm in /home/delemo_b/epitech_1/corewar/asm/src/asm
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Wed Mar 20 15:24:56 2013 barthelemy delemotte
** Last update Sat Mar 30 16:54:51 2013 damien sauvalle
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"error.h"
#include	"my.h"
#include	"op.h"

static char	*get_extra_value(char *line, const char *field)
{
  char		*value;
  int		len;

  line += my_strlen(field);
  if (line[0] != ' ' || line[1] != '\"')
    return (error_ptr("bad command string argument\n"));
  line += 2;
  len = 0;
  while (line[len] && line[len] != '\"')
    len++;
  if (line[len] != '\"')
    return (error_ptr("bad command string argument\n"));
  value = xmalloc((len + 1) * sizeof(char));
  my_strncpy(value, line, len);
  value[len] = '\0';
  return (value);
}

static int	parse_line(t_asm *asm_d, char *line)
{
  if (my_strncmp(line, NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)) == 0)
    {
      asm_d->name = get_extra_value(line, NAME_CMD_STRING);
      if (asm_d->name == NULL)
	return (RET_FAILURE);
    }
  if (my_strncmp(line, COMMENT_CMD_STRING, my_strlen(COMMENT_CMD_STRING)) == 0)
    {
      asm_d->comment = get_extra_value(line, COMMENT_CMD_STRING);
      if (asm_d->comment == NULL)
	return (RET_FAILURE);
    }
  return (RET_SUCCESS);
}

static int	check_error(t_asm *asm_d)
{
  if (asm_d->name == NULL)
    return (error_int("missing program name\n"));
  if (asm_d->comment == NULL)
    return (error_int("missing program comment\n"));
  if (my_strlen(asm_d->name) > PROG_NAME_LENGTH)
    return (error_int("program name lenght is too long\n"));
  if (my_strlen(asm_d->comment) > COMMENT_LENGTH)
    return (error_int("comment lenght is too long\n"));
  return (RET_SUCCESS);
}

int		asm_fill_extra_datas(t_asm *asm_d)
{
  t_list_item	*item;
  t_list_item	*to_delete;
  char		*line;

  item = asm_d->file->top;
  while (item)
    {
      line = item->data;
      if (line[0] == '.')
	{
	  to_delete = item;
	  item = item->next;
	  if (parse_line(asm_d, line) == RET_FAILURE)
	    return (RET_FAILURE);
	  my_list_delete(asm_d->file, to_delete);
	}
      else
	item = item->next;
    }
  return (check_error(asm_d));
}
