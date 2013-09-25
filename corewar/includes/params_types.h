/*
** params_types.h for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/includes
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sat Mar  9 07:54:58 2013 barthelemy delemotte
** Last update Sat Mar 30 22:46:28 2013 barthelemy delemotte
*/

#ifndef		PARAMS_TYPES_H_
# define	PARAMS_TYPES_H_

#include	"my.h"

#define		PARAMS_ALLOWED	"-dump -a -n"

typedef struct	s_params
{
  int		dump_cycle;
  t_list	*programs;
}		t_params;

#endif /* !PARAMS_TYPES_H_ */
