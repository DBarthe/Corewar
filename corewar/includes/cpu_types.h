/*
** cpu_types.h for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/includes
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sat Mar  9 07:48:32 2013 barthelemy delemotte
** Last update Sun Mar 31 18:59:04 2013 raphael defreitas
*/

#ifndef		CPU_TYPES_H_
# define	CPU_TYPES_H_

#include	"my.h"

typedef struct
{
  t_list	*processes;
  void		(*hook_process)();
}		t_cpu;

#endif /* !CPU_TYPES_H_ */
