/*
** brain_types.h for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/includes
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sat Mar  9 07:45:03 2013 barthelemy delemotte
** Last update Sat Mar 30 14:30:00 2013 barthelemy delemotte
*/

#ifndef		BRAIN_TYPES_H_
# define	BRAIN_TYPES_H_

#include	"my.h"
#include	"game_types.h"
#include	"cpu_types.h"
#include	"ram_types.h"

typedef struct
{
  t_game	*game;
  t_cpu		*cpu;
  t_ram		*ram;
  t_list	*programs;
}		t_brain;

#endif /* !BRAIN_TYPES_H_ */
