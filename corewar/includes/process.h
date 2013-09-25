/*
** process.h for corewar in /home/raphy/Projects/prog_elem/corewar/corewar/includes
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jan 28 16:13:00 2013 raphael defreitas
** Last update Sat Mar 30 14:35:36 2013 barthelemy delemotte
*/

#ifndef		PROCESS_H_
# define	PROCESS_H_

#include	"process_types.h"
#include	"program_types.h"
#include	"game_types.h"
#include	"ram_types.h"

t_process	*process_new(void);
void		process_free(t_process *process);
int		process_init(t_process *process, t_program *program);
t_process	*process_create(t_program *program);
t_process	*process_dup(t_process *src, int pid);
int		process_disp(t_process *process);
int		process_execute(t_process *process, t_game *game, t_ram *ram);
int		process_get_registre(t_process *process, int reg_no);
int		process_set_registre(t_process *process, int reg_no, int value);

#endif /* !PROCESS_H_ */
