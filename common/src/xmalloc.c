/*
** xmalloc.c for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/src
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sat Mar 16 19:04:23 2013 barthelemy delemotte
** Last update Fri Apr  5 18:09:33 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"

void		*xmalloc(unsigned int size)
{
  void		*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    {
      my_fprintf(ERR_OUTPUT, "Can't perform malloc\n");
      exit(0);
    }
  return (ptr);
}
