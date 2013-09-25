/*
** instruction_types.h for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/includes
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sat Mar  9 07:51:25 2013 barthelemy delemotte
** Last update Sun Mar 31 11:53:23 2013 barthelemy delemotte
*/

#ifndef		INSTRUCTION_TYPES_H_
# define	INSTRUCTION_TYPES_H_

#include	"op.h"

#define		ARGC_UNDEF	-1
#define		RET_ERR_INST	2

typedef struct	s_instruction
{
  char		*data;
  int		data_len;
  int		argv[MAX_ARGS_NUMBER];
  int		argc;
}		t_instruction;

#endif /* !INSTRUCTION_TYPES_H_ */
