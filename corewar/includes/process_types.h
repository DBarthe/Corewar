/*
** process_types.h for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/includes
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sat Mar  9 07:56:13 2013 barthelemy delemotte
** Last update Sat Mar 30 14:35:54 2013 barthelemy delemotte
*/

#ifndef		PROCESS_TYPES_H_
# define	PROCESS_TYPES_H_

#include	"op.h"
#include	"instruction_types.h"

#define		CARRY_SUCCESS	1
#define		CARRY_ERROR	0
#define		PID_UNDEF	-1

typedef struct
{
  int		pid;
  int		pc;
  int		registres[REG_NUMBER];
  char		carry;
  int		cycles_to_wait;
  t_instruction	*next_instruction;
}		t_process;

#endif /* !PROCESS_TYPES_H_ */
