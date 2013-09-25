/*
** asm_write.c for corewar - asm in /home/delemo_b/epitech_1/corewar/asm/src/asm
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Wed Mar 20 16:01:57 2013 barthelemy delemotte
** Last update Sun Mar 31 09:55:13 2013 damien sauvalle
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"asm.h"
#include	"my.h"
#include	"op.h"
#include	"error.h"
#include	"instruction.h"

static int	write_magic(t_asm *asm_d)
{
  if (write(asm_d->fd, COREWAR_EXEC_MAGIC, MAGIC_LEN) == -1)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}

static int	write_str(int fd, const char *str, int len_max)
{
  int		zero_nbr;

  if (write(fd, str, my_strlen(str)) == -1)
    return (RET_FAILURE);
  zero_nbr = len_max - my_strlen(str);
  while (--zero_nbr >= 0)
    my_fputchar(fd, 0);
  return (RET_SUCCESS);
}

static int	write_program_len(t_asm *asm_d)
{
  char		*buf;
  int		i;

  i = 0;
  while (i++ < 4)
    my_fputchar(asm_d->fd, 0);
  buf = xmalloc(sizeof(char) * SIZE_CONTENT_LENGTH);
  i = asm_d->code_len;
  if (coffee_write_nbr(buf, i, 4, UNSIGNED) == RET_FAILURE)
    {
      free(buf);
      return (RET_FAILURE);
    }
  if (write(asm_d->fd, buf, 4) == -1)
    {
      free(buf);
      return (RET_FAILURE);
    }
  free(buf);
  return (RET_SUCCESS);
}

static int	write_header(t_asm *asm_d)
{
  if ((write_magic(asm_d) == RET_FAILURE) ||
      (write_str(asm_d->fd, asm_d->name, PROG_NAME_LENGTH) == RET_FAILURE) ||
      (write_program_len(asm_d) == RET_FAILURE) ||
      (write_str(asm_d->fd, asm_d->comment, COMMENT_LENGTH + 4)
       == RET_FAILURE))
    {
      my_printf("Asm : Write header fail\n");
      return (RET_FAILURE);
    }
  return (RET_SUCCESS);
}

int		asm_write(t_asm *asm_d)
{
  if (write_header(asm_d) == RET_FAILURE ||
      write(asm_d->fd, asm_d->code, asm_d->code_len) == -1)
    return (error_int("Impossible to write in the .cor file\n"));
  return (RET_SUCCESS);
}
