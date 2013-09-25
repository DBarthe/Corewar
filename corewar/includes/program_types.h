/*
** program_types.h for corewar - vm in /home/delemo_b/epitech_1/corewar/corewar/includes
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Sat Mar  9 07:57:40 2013 barthelemy delemotte
** Last update Sat Mar 30 14:36:29 2013 barthelemy delemotte
*/

#ifndef		PROGRAM_TYPES_H_
# define	PROGRAM_TYPES_H_

typedef struct	s_program
{
  char		*file;
  int		player_id;
  int		load_addr;
  char		*name;
  int		data_len;
  int		code_len;
  char		*data;
  char		*code;
}		t_program;

#endif /* !PROGRAM_TYPES_H_ */
