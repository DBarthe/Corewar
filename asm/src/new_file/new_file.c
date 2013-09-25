/*
** new_file.c for corewar in /home/lefebv_z//projet/c-prog-elem/corewar/asm/src
** 
** Made by marie lefebvre
** Login   <lefebv_z@epitech.net>
** 
** Started on  Thu Feb 14 17:46:57 2013 marie lefebvre
** Last update Sat Mar 30 15:08:28 2013 marie lefebvre
*/

#include	<stdlib.h>
#include	<fcntl.h>
#include	"asm.h"
#include	"error.h"
#include	"instruction.h"

static char	*new_name_cor(char *name)
{
  int		len;
  char		*new;
  int		i;
  int		j;

  i = my_strlen(name) - 1;
  while (i != 0 && name[i - 1] != '/')
    i--;
  len = 0;
  while (name[i + len] != '.' && name[i + len] != '\0')
    len++;
  new = xmalloc(sizeof(char) * (len + 5));
  j = 0;
  while (j < len)
    new[j++] = name[i++];
  new[j] = '\0';
  my_strcat(new, ".cor");
  return (new);
}

int		create_file(char *name)
{
  char		*name_cor;
  int		fd;

  if ((name_cor = new_name_cor(name)) == NULL)
    return (RET_FAILURE);
  fd = open(name_cor, O_CREAT | O_WRONLY | O_TRUNC, 0664);
  free(name_cor);
  if (fd == -1)
    v_error_int("Can't open file\n", RET_ERROR);
  return (fd);
}
