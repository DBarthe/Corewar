/*
** program.h for vm - corewar in /home/delemo_b/epitech_1/corewar/corewar/includes
** 
** Made by barthelemy delemotte
** Login   <delemo_b@epitech.net>
** 
** Started on  Mon Jan 28 17:27:13 2013 barthelemy delemotte
** Last update Sat Mar 30 14:36:11 2013 barthelemy delemotte
*/

#ifndef		PROGRAM_H_
# define	PROGRAM_H_

#include	"program_types.h"
#include	"my.h"

t_program	*program_new(void);
void		program_free(t_program *program);
int		program_init_load_addr(t_list *programs);
int		program_load_datas(t_list *programs);
int		program_list_init(t_list *programs);
int		program_init_name(t_program *program);
int		program_attrib_id(t_list *programs);
void		program_display(t_program *program);

#endif /* !PROGRAM_H_ */
