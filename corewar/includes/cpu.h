/*
** cpu.h for corewar in /home/raphy/Projects/prog_elem/corewar/corewar/includes
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jan 28 16:11:54 2013 raphael defreitas
** Last update Sat Mar 30 16:17:38 2013 barthelemy delemotte
*/

#ifndef		CPU_H_
# define	CPU_H_

#include	"cpu_types.h"
#include	"game_types.h"
#include	"ram_types.h"
#include	"process_types.h"

t_cpu		*cpu_new(void);
void		cpu_free(t_cpu *cpu);
int		cpu_create_processes(t_cpu *cpu, t_list *programs);
int		cpu_disp_processes(t_cpu *cpu);
int		cpu_execution(t_cpu *cpu, t_game *game, t_ram *ram);
int		cpu_add_process(t_cpu *cpu_p, t_process *process);
int		cpu_kill_process(t_cpu *cpu, int pid);

#endif /* !CPU_H_ */
