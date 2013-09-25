/*
** brain.h for corewar in /home/raphy/Projects/prog_elem/corewar/corewar/includes
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jan 28 16:12:14 2013 raphael defreitas
** Last update Sat Mar 30 14:29:41 2013 barthelemy delemotte
*/

#ifndef		BRAIN_H_
# define	BRAIN_H_

#include	"brain_types.h"
#include	"params_types.h"

t_brain		*brain_new(void);
void		brain_free(t_brain *brain);
int		brain_init(t_brain *brain, t_game *game,
			   t_cpu *cpu, t_ram *ram);
int		brain_load(t_brain *brain, t_params *params);
int		brain_put_programs(t_brain *brain);
int		brain_run(t_brain *brain);
int		brain_run_x(t_brain *brain);

#endif /* !BRAIN_H_ */
