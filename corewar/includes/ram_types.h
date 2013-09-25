/*
** ram_types.h for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/includes
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sat Mar  9 07:58:50 2013 barthelemy delemotte
** Last update Sun Mar 31 01:18:37 2013 raphael defreitas
*/

#ifndef		RAM_TYPES_H_
# define	RAM_TYPES_H_

typedef struct	s_ram
{
  char		*arena;
  void		(*hook_set)();
  int		last_user_no;
}		t_ram;

#endif /* !RAM_TYPES_H_ */
