/*
** params_free.c for vm - corewar in /home/delemo_b/epitech_1/corewar/corewar/src/params
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Jan 28 16:37:06 2013 barthelemy delemotte
** Last update Fri Mar  8 16:29:28 2013 barthelemy delemotte
*/

#include	<stdlib.h>
#include	"params.h"

void		params_free(t_params *params)
{
  if (params != NULL)
    {
      if (params->programs != NULL)
	{
	  params->programs = NULL;
	}
      free(params);
    }
}
