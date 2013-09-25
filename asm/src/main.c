/*
** main.c for corewar in /home/sauval_d//corewar/asm/src
** 
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
** 
** Started on  Tue Jan 29 14:09:08 2013 damien sauvalle
** Last update Sun Mar 31 09:37:56 2013 damien sauvalle
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"my.h"
#include	"op.h"
#include	"parser.h"
#include	"instruction.h"
#include	"asm.h"

static char	*recup_name(char *av)
{
  char		*str;
  int		len;
  int		i;

  len = my_strlen(av);
  i = len;
  while (av[i] != '/' && i != 0)
    i--;
  len = len - i;
  str = xmalloc(sizeof(char) * (len + 1));
  str[0] = '\0';
  if (av[i] == '/')
    i++;
  my_strcpy(str, av + i);
  return (str);
}

int		main(int ac, char **av)
{
  t_list	*file;
  char		*name_file;
  int		fd;
  int		ret;

  if (ac != 2)
    {
      my_printf("Bad usage: ./asm file\n");
      return (EXIT_FAILURE);
    }
  if ((file = recovery(av[1])) == NULL)
    return (EXIT_FAILURE);
  if ((fd = create_file(av[1])) == -1)
    return (EXIT_FAILURE);
  name_file = recup_name(av[1]);
  ret = asm_assamble(file, fd, name_file);
  close(fd);
  free(name_file);
  return (ret);
}
