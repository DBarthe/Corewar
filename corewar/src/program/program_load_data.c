/*
** program_load_data.c for vm - corewar in /home/delemo_b/epitech_1/corewar/corewar/src/program
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Fri Feb  1 16:24:31 2013 barthelemy delemotte
** Last update Fri Mar 29 13:12:23 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<sys/types.h>
#include	"program.h"
#include	"my.h"
#include	"op.h"
#include	"error.h"

static int	get_data_size(int fd)
{
  int		ret;
  char		buf[64];
  int		size;

  size = 0;
  while ((ret = read(fd, buf, 64)) != 0)
    {
      if (ret < 0)
	return (error_int(RET_ERROR, ERR_READ));
      size += ret;
    }
  return (size);
}

static int	load_data(t_program *program)
{
  int		fd;

  if ((fd = open(program->file, O_RDONLY)) == RET_ERROR)
    return (error_int(RET_FAILURE, ERR_OPEN_RD));
  if ((program->data_len = get_data_size(fd)) == RET_ERROR)
    return (RET_FAILURE);
  if (lseek(fd, SEEK_SET, 0) == RET_ERROR)
    return (error_int(RET_FAILURE, ERR_LSEEK));
  if ((program->data = malloc(program->data_len * sizeof(char))) == NULL)
    return (error_int(RET_FAILURE, ERR_MALLOC));
  if (read(fd, program->data, program->data_len) != program->data_len)
    return (error_int(RET_FAILURE, ERR_READ));
  if (close(fd) == RET_ERROR)
    return (error_int(RET_SUCCESS, WAR_CLOSE));
  return (RET_SUCCESS);
}

static int	check_magic(char *data)
{
  static char	cor_magic[4] = COREWAR_EXEC_MAGIC;

  if (my_mem_isequal(data, cor_magic, 4) == false)
    return (error_int(RET_FAILURE, ERR_BAD_MAGIC));
  return (RET_SUCCESS);
}

int		program_load_datas(t_list *programs)
{
  t_list_item	*item;
  t_program	*program;
  int		header_len;

  header_len = MAGIC_LEN + PROG_NAME_LENGTH
    + SIZE_CONTENT_LENGTH + COMMENT_LENGTH + 4;
  item = programs->top;
  while (item != NULL)
    {
      program = (t_program *)item->data;
      if (load_data(program) == RET_FAILURE)
	return (RET_FAILURE);
      if (program->data_len < header_len)
	return (error_int(RET_FAILURE, ERR_INVALID_HEADER));
      else if (program->data_len == header_len)
	return (error_int(RET_FAILURE, ERR_CONTENT_EMPTY));
      if (check_magic(program->data) == RET_FAILURE)
	return (RET_FAILURE);
      program->code = program->data + header_len;
      program->code_len = program->data_len - header_len;
      item = item->next;
    }
  return (RET_SUCCESS);
}
