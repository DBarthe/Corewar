/*
** recovery.c for corewar in /home/sauval_d//corewar/asm/src
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Tue Jan 29 14:26:24 2013 damien sauvalle
** Last update Sat Mar 30 16:57:16 2013 damien sauvalle
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	"my.h"
#include	"parser.h"
#include	"op.h"

static t_list	*open_file(char *av)
{
  int		fd;
  char		*data;
  t_list	*gen;

  fd = open(av, O_RDONLY);
  if (fd == -1)
    {
      my_fputstr(2, "Open error\n");
      return (NULL);
    }
  gen = my_list_new(LIST_LINKED, free);
  while ((data = my_getline(fd)))
    {
      if (data[0] != COMMENT_CHAR)
	my_list_enqueue(gen, data);
      else
	free(data);
    }
  return (gen);
}

t_list		*recovery(char *av)
{
  t_list	*file;

  if ((file = open_file(av)) == NULL)
    return (NULL);
  remove_comment(file);
  return (file);
}
