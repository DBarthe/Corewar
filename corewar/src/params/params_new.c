/*
** params_new.c for vm - corewar in /home/delemo_b/epitech_1/corewar/corewar/src/params
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Jan 28 16:30:25 2013 barthelemy delemotte
** Last update Sat Mar 30 22:45:17 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"my.h"
#include	"params.h"
#include	"program.h"

t_params	*params_new(void)
{
  t_params	*params;

  params = xmalloc(sizeof(t_params));
  if (params == NULL)
    return (NULL);
  params->dump_cycle = 0;
  params->programs = my_list_new(LIST_LINKED, &program_free);
  if (params->programs == NULL)
    {
      free(params);
      return (NULL);
    }
  return (params);
}
